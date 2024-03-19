/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** arcade_manage_lib
*/

#include "Arcade.hpp"
#include "SafeDiv.hpp"

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
    if (this->_lib.currentDisplay == -1 || !this->_clock.isElapsed()) {
        return;
    }
    this->_lib.currentDisplay = Arc::safeModulo<int>(this->_lib.currentDisplay + 1, this->_lib.graphical.size());
    this->loadSelectedDisplay();
    this->_clock.reset();
}

void Arc::Arcade::loadNextGame()
{
    if (this->_lib.currentGame == -1) {
        return;
    }
    this->_lib.currentGame = Arc::safeModulo<int>(this->_lib.currentGame + 1, this->_lib.game.size());
    this->loadSelectedGame();
}

void Arc::Arcade::loadSelectedGame()
{
    if (this->_lib.currentGame == -1) {
        return;
    }
    this->gameModule->stop();
    delete this->gameModule;
    this->gameLoader.close();
    this->gameLoader.load(this->_lib.game.at(this->_lib.currentGame).path);
    this->gameModule = this->gameLoader.getInstance("entryPoint");
    this->gameModule->init();
}

void Arc::Arcade::loadSelectedDisplay()
{
    if (this->_lib.currentDisplay == -1) {
        return;
    }
    this->displayModule->stop();
    delete this->displayModule;
    this->displayLoader.close();
    this->displayLoader.load(this->_lib.graphical.at(this->_lib.currentDisplay).path);
    this->displayModule = this->displayLoader.getInstance("entryPoint");
    this->displayModule->init();
}

void Arc::Arcade::loadMenu()
{
    for (std::size_t i = 0; i < this->_lib.game.size(); ++i) {
        if (this->_lib.game[i].name == "arcade_G_menu") {
            this->_lib.currentGame = i;
            break;
        }
    }
    loadSelectedGame();
}
