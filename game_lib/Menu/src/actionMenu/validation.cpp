/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** validation
*/

#include "Menu.hpp"
#include "getFileContent.hpp"

void Arc::Menu::defineNewCursorGame(const std::string &filename)
{
    for (const auto &gamePath : this->gameData.lib.game) {
        if (getFileName(gamePath.path) == filename) {
            _cursorPlace.gameLib = _cursorPlace.elemInSelect;
            this->gameData.lib.currentGame = _cursorPlace.gameLib;
        }
    }
}

void Arc::Menu::defineNewCursorGraphical(const std::string &filename)
{
    for (const auto &graphicalPath : this->gameData.lib.graphical) {
        if (getFileName(graphicalPath.path) == filename) {
            _cursorPlace.graphicalLib = _cursorPlace.elemInSelect;
            this->gameData.lib.currentDisplay = _cursorPlace.graphicalLib - this->gameData.lib.game.size();
        }
    }
}

void Arc::Menu::setDefaultName()
{
    if (this->gameData.player.userName.size() == 0) {
        Arc::FileContent::printContentToFile("./game_src/username.txt", "default player");
    }
}

void Arc::Menu::handleValidation(const std::string &filename)
{
    if (filename == VALIDATE) {
        if (this->gameData.lib.currentGame >= 0 && this->gameData.lib.currentDisplay >= 0) {
            this->gameData.lib.libState = Arc::LibState::NEW_SELECTION;
        }
    }
}

void Arc::Menu::validateChoice(const std::string &filename)
{
    defineNewCursorGame(filename);
    defineNewCursorGraphical(filename);
    handleActionUsername(filename);
}
