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

Arc::Arcade::~Arcade()
{
    delete this->displayModule;
    delete this->gameModule;
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
    this->_clock.setCooldown(std::chrono::milliseconds(500));
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
    for (const Arc::EventType &eventIt : eventList.eventType) {
        if (eventIt == eventType) {
            return true;
        }
    }
    return false;
}

void Arc::Arcade::handleCoreEvent(const Arc::Event &eventList)
{
    if (eventContain(eventList, Arc::EventType::NEXT_GAME)) {
        loadNextGame();
    } else if (eventContain(eventList, Arc::EventType::NEXT_DISPLAY)) {
        loadNextDisplay();
    } else if (eventContain(eventList, Arc::EventType::BACK_MENU)) {
        loadMenu();
    } else if (eventContain(eventList, Arc::EventType::RESTART)) {
        loadSelectedGame();
    }
}

void Arc::Arcade::manageLibData(const Arc::Lib &libData)
{
    if (libData.libState == Arc::LibState::CURRENT_NOT_INIT
    && this->_lib.currentGame == -1 && this->_lib.currentDisplay == -1) {
        this->_lib.game = libData.game;
        this->_lib.graphical = libData.graphical;
        this->getCurrentLibLoaded();
    }
    if (libData.libState == Arc::LibState::NEW_SELECTION) {
        this->_lib.currentDisplay = libData.currentDisplay;
        this->_lib.currentGame = libData.currentGame;
        loadSelectedDisplay();
        loadSelectedGame();
    }
}

void Arc::Arcade::loop()
{
    this->displayModule->init();
    this->gameModule->init();
    this->_clock.start();

    while (true)
    {
        Arc::FrameRate::start();

        const Arc::Event &eventList = this->displayModule->getEvent();
        if (eventContain(eventList, Arc::EventType::EXIT)) {
            break;
        }
        handleCoreEvent(eventList);
        const GameData &data = this->gameModule->update(eventList);
        this->displayModule->refresh(data);
        manageLibData(data.lib);

        Arc::FrameRate::end();
    }
    this->gameModule->stop();
    this->displayModule->stop();
}
