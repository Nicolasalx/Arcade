
# Arcade

## Project Architecture

https://lucid.app/lucidchart/6680fd71-2d91-41ca-bd80-dfa4c7227fbd/edit?viewport_loc=839%2C-53%2C2219%2C1059%2CL.BeP2~polPs&invitationId=inv_59fe9b67-f6d2-46ce-896b-5d7a95774716

##  How to implement a new graphic library

To create a new graphical library for the arcade you will need to create a new shared library that will placed in the ```lib/``` directory.

1. Lib core function

In the library you will need to implement 2 core function that will be needed by the arcade to :

- get an instance of you class graphical library
- get the name and type of you library

Here is function prototype hande how to implement them :

```c++
Arc::IDisplayModule *entryPoint(void);
```
```entryPoint``` is the function that will be called by the arcade to get an instance of you graphical class as the interface IDisplayModule.

Here is a code example where you just have to replace ```YOUR_GRAPHICAL_LIB``` with the name of you class
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
this function will return a string to indicate the type of the library and it's name.
Here is the format to respect : ```arcade_[G|D]_[LIB_NAME]```
- ```G``` stand for indicating that the lib is a game
- ```D``` stand for indicating that the lib is a display

For example if you create a vulkan implementation for arcade the name returned will be: ```arcade_D_vulkan```

----

2. Interface implementation

For your graphical library you will need to create a class that will derivate from ADisplayModule that also derive from IDisplayModule:

In your class you will need to implement those 4 function:

```c++
void init();
```
The ```init``` function will be the first function call by arcade to init your graphical environement, for example it's here that you create your window if you need one, or init or your intern data to your class.

```c++
Arc::Event getEvent();
```
The ```getEvent``` function will be the first function called every frame of the game, this function return the structure Event wich containt a `buffer` field and a `eventType` field, when you received event in your library you need to add it to the `eventType` list or if the field in the player structure `ignoreKey` is true all the input are put in the `buffer` field. The `event` returned by this function will be given to the game that the player actually playing.

```c++
void refresh(const Arc::GameData &gameData);
```
The `refresh` function will be called every frame after the `getEnvent` function, `refresh` take as argument `gameData` this structure represent all the data that need to be displayed to the user on the screen. In refresh you need to display all the tile of all the sub structure of `GameData` (see the UML diagram). You also need to display the text in the `Text` structure.

```c++
void stop();
```
The ```stop``` function will be call by arcade to shutdown your graphical environement, for example it's here that you destroy your window and all your object, or free your internal data of your class.

## How to implement a new game
