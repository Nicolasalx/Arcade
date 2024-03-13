/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** arcade
*/

#include "Arcade.hpp"
#include "my_tracked_exception.hpp"
#include "DLLoader.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include <iostream>

Arc::Arcade::Arcade(int argc, const char **argv)
{
    if (argc != 2) {
        throw my::tracked_exception("Invalide nb of arg\n\n"
           "Usage: ./arcade graphical_lib.so\n\n"
           "\tgraphical_lib.so is a dynamic library that"
           "implement all the method of IDisplayModule\n\n");
    }
    this->graphicalLib = std::string(argv[1]);
}

void Arc::Arcade::launch()
{
    this->displayLoader.load(this->graphicalLib);
    this->displayModule = displayLoader.getInstance("entryPoint");

    this->gameLoader.load("./lib/arcade_menu.so");
    this->gameModule = this->gameLoader.getInstance("entryPoint");
}

void Arc::Arcade::loop()
{
    this->displayModule->init();
    this->gameModule->init();

    for (size_t i = 0; i < 10; ++i)
    {
        this->displayModule->refresh(this->gameModule->update(this->displayModule->getEvent()));
    }
    this->gameModule->stop();
    this->displayModule->stop();
}
