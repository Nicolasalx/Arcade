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
#include "SafeDiv.hpp"

Arc::Arcade::~Arcade()
{
    if (this->displayModule != nullptr) {
        delete this->displayModule;
    }
    if (this->gameModule != nullptr) {
        delete this->gameModule;
    }
}

void Arc::Arcade::start(int argc, const char **argv)
{
    if (argc != 2) {
        throw my::tracked_exception("Invalide nb of arg\n\n"
           "Usage: ./arcade graphical_lib.so\n\n"
           "\tgraphical_lib.so is a dynamic library that"
           "implement all the method of IDisplayModule\n\n");
    }
    this->displayName = std::string(argv[1]);
}

void Arc::Arcade::launch()
{
    this->displayLoader.load(this->displayName);
    this->displayName = this->displayLoader.getName();
    this->gameLoader.load("./lib/arcade_menu.so");
    this->gameName = this->gameLoader.getName();

    if (!this->displayName.starts_with("arcade_D_")) {
        throw my::tracked_exception("Invalid graphical lib.");
    }
    this->displayModule = this->displayLoader.getInstance("entryPoint");
    this->gameModule = this->gameLoader.getInstance("entryPoint");
}

bool Arc::Arcade::eventContain(const Arc::Event &eventList, const Arc::EventType &eventType)
{
    for (std::size_t i = 0; i < eventList.eventType.size(); ++i) {
        if (eventList.eventType[i] == eventType) {
            return true;
        }
    }
    return false;
}

void Arc::Arcade::getCurrentLibLoaded()
{
    for (std::size_t i = 0; i < this->_lib.game.size(); ++i) {
        if (this->_lib.game[i].name == this->gameName) {
            this->_lib.currentGame = i;
        }
    }
    for (std::size_t i = 0; i < this->_lib.graphical.size(); ++i) {
        if (this->_lib.graphical[i].name == this->displayName) {
            this->_lib.currentDisplay = i;
        }
    }
}

void Arc::Arcade::loadNextDisplay()
{
    if (this->_lib.currentDisplay == -1 || this->_clock.isElapsed() == false) {
        return;
    }
    this->displayModule->stop();
    delete this->displayModule;
    this->displayLoader.close();
    this->_lib.currentDisplay = Arc::safeModulo<int>(this->_lib.currentDisplay + 1, this->_lib.graphical.size());
    this->displayLoader.load(this->_lib.graphical.at(this->_lib.currentDisplay).path);
    this->displayModule = this->displayLoader.getInstance("entryPoint");
    this->displayModule->init();
    this->_clock.reset();
}

void Arc::Arcade::loadNextGame()
{
    if (this->_lib.currentGame == -1 || this->_clock.isElapsed() == false) {
        return;
    }
    this->gameModule->stop();
    delete this->gameModule;
    this->gameLoader.close();
    this->_lib.currentGame = Arc::safeModulo<int>(this->_lib.currentGame + 1, this->_lib.game.size());
    this->gameLoader.load(this->_lib.game.at(this->_lib.currentGame).path);
    this->gameModule = this->gameLoader.getInstance("entryPoint");
    this->gameModule->init();
    this->_clock.reset();
}

void Arc::Arcade::loop()
{
    this->gameModule->init();
    this->displayModule->init();
    this->_clock.setCooldown(std::chrono::milliseconds(500));
    this->_clock.start();

    while (true)
    {
        Arc::FrameRate::start();

        Arc::Event eventList = this->displayModule->getEvent();
        if (eventContain(eventList, Arc::EventType::EXIT)) {
            break;
        }
        if (eventContain(eventList, Arc::EventType::NEXT_GAME)) {
            loadNextGame();
        }
        if (eventContain(eventList, Arc::EventType::NEXT_DISPLAY)) {
            loadNextDisplay();
        }
        GameData data = this->gameModule->update(eventList);

        if (data.lib.libState == Arc::LibState::CURRENT_NOT_INIT
        && this->_lib.currentGame == -1 && this->_lib.currentDisplay == -1) {
            this->_lib.game = data.lib.game;
            this->_lib.graphical = data.lib.graphical;
            this->getCurrentLibLoaded();
        }
//        if (data.lib.libState == Arc::LibState::NEW_SELECTION) {
//            
//        }
        this->displayModule->refresh(data);

        Arc::FrameRate::end();
    }
    this->displayModule->stop();
    this->gameModule->stop();
}
