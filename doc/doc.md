
# Arcade

## Project Architecture

[UML Diagram](https://lucid.app/lucidchart/6680fd71-2d91-41ca-bd80-dfa4c7227fbd/edit?viewport_loc=839%2C-53%2C2219%2C1059%2CL.BeP2~polPs&invitationId=inv_59fe9b67-f6d2-46ce-896b-5d7a95774716)

##  How to implement a new graphic library

To create a new graphical library for the arcade you will need to create a new shared library that will be placed in the ```lib/``` directory.

1. Lib core function

In the library you will need to implement 2 core functions that will be needed by the arcade:

- get an instance of your class graphical library
- get the name and type of your library

Here is functions prototypes showing how to implement them :

```c++
Arc::IDisplayModule *entryPoint(void);
```
```entryPoint``` is the function that will be called by the arcade to get an instance of your graphical class as the interface IDisplayModule.

Here is a code example where you just have to replace ```YOUR_GRAPHICAL_LIB``` with the name of your class
```c++
extern "C"
{
    Arc::IDisplayModule *entryPoint(void)
    {
        return new YOUR_GRAPHICAL_LIB();
    }
}
```

The second function is ```getName```:

```c++
const std::string &getName();
```
this function will return a string to indicate the type of the library and its name.
Here is the format to respect : ```arcade_[G|D]_[LIB_NAME]```
- ```G```stands for indicating that the lib is a game
- ```D```stands for indicating that the lib is a display

For example, if you create a vulkan implementation for Arcade the name returned will be: ```arcade_D_vulkan```

----

2. Interface implementation

For your graphical library you will need to create a class that will be derived from ADisplayModule that also derives from IDisplayModule:

![image](https://github.com/EpitechPromo2027/B-OOP-400-PAR-4-1-arcade-thibaud.cathala/assets/114906947/33fc11a6-f98e-403c-a5b4-c2c421e8add2)

In your class you will need to implement those 4 functions:

```c++
YOUR_CLASS_CONSTRUCTOR();
```
The ```constructor``` will be the first function call by Arcade to init your graphical environment, for example, it's here that you create your window if you need one, or init or your intern data to your class.

```c++
Arc::Event getEvent();
```
The ```getEvent``` function will be the first function called every frame of the game, this function returns the structure Event which contains a `buffer` field and an `eventType` field, when you receive an event in your library you need to add it to the `eventType` list or if the field in the player structure `ignoreKey` is true all the input are put in the `buffer` field. The `event` returned by this function will be given to the game that the player playing.

Here is the mandatory keyEvent that you need to implement:

![image](https://github.com/EpitechPromo2027/B-OOP-400-PAR-4-1-arcade-thibaud.cathala/assets/114906947/558043c6-0e4f-40dd-b40e-9a1ceaba12ad)


```c++
void refresh(const Arc::GameData &gameData);
```
The `refresh` function will be called every frame after the `getEnvent` function, `refresh` takes as argument `gameData` this structure represents all the data that need to be displayed to the user on the screen. In refresh you need to display all the tiles of all the substructure of `GameData` (see the UML diagram). You also need to display the text in the `Text` structure.

You also need to respect the display pipeline to display the game in its intended way:

![image](https://github.com/EpitechPromo2027/B-OOP-400-PAR-4-1-arcade-thibaud.cathala/assets/114906947/7b902c3f-ff60-4f45-8938-5065ac07e324)

```c++
~YOUR_CLASS_DESTRUCTOR();
```
The ```destructor``` will be called by Arcade to shutdown your graphical environment, for example, it's here that you destroy your window and all your objects, or free the internal data of your class.

## How to implement a new game
