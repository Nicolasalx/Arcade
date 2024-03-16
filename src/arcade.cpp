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
#include "FrameRate.hpp"
#include "my_print.hpp"
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

Arc::Arcade::~Arcade()
{
    if (this->displayModule != nullptr) {
        delete this->displayModule;
    }
    if (this->gameModule != nullptr) {
        delete this->gameModule;
    }
}

void Arc::Arcade::launch()
{
    this->displayLoader.load(this->graphicalLib);
    this->displayModule = displayLoader.getInstance("entryPoint");

    if (!this->displayLoader.getName().starts_with("arcade_D_")) {
        throw my::tracked_exception("Invalid graphical lib.");
    }

    this->gameLoader.load("./lib/arcade_menu.so");
    this->gameModule = this->gameLoader.getInstance("entryPoint");
}

static bool exitDetected(const Arc::Event &eventList)
{
    for (size_t i = 0; i < eventList.eventType.size(); ++i) {
        if (eventList.eventType[i] == Arc::EventType::EXIT) {
            return true;
        }
    }
    return false;
}

void Arc::Arcade::loop()
{
    this->displayModule->init();
    this->gameModule->init();

    while (true)
    {
        Arc::FrameRate::start();

        Arc::Event eventList = this->displayModule->getEvent();
        if (exitDetected(eventList)) {
            break;
        }
        const GameData &data = this->gameModule->update(eventList);
        if (data.lib.libState == Arc::LibState::CURRENT_NOT_INIT
            && this->_lib.currentGame != -1) {
            this->_lib.game = data.lib.game;
            this->_lib.graphical = data.lib.graphical;
            this->_lib.currentGame = 0;
            this->_lib.currentDisplay = 0;
            my::printsl(this->_lib.game, [](const LibInfo &test) { std::cout << "[" << test.name << ", " << test.path<< "]";});
            my::printsl(this->_lib.graphical, [](const LibInfo &test) { std::cout << "[" << test.name << ", " << test.path<< "]";});
        }
//        if (data.lib.libState == Arc::LibState::NEW_SELECTION) {
//            
//        }
        this->displayModule->refresh(data);

        Arc::FrameRate::end();
    }
    this->gameModule->stop();
    this->displayModule->stop();
}
