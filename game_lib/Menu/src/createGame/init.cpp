/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** init
*/

#include "Menu.hpp"

void Arc::Menu::createAllText()
{
    double posY = 250;

    createTextWithLib(GAME_LIST, (Arc::Pos) {500, 200}, NOT_SELECTABLE);
    createTextWithLib(GRAPHICAL_LIST, (Arc::Pos) {1100, 200}, NOT_SELECTABLE);
    for (const auto &libGame : this->gameData.lib.game) {
        createTextWithLib(libGame.path, (Arc::Pos) {500, posY += 50}, SELECTABLE);
    }
    posY = 250;
    for (const auto &libGraphical : this->gameData.lib.graphical) {
        createTextWithLib(libGraphical.path, (Arc::Pos) {1100, posY += 50}, SELECTABLE);
    }
    createTextWithLib(USERNAME, (Arc::Pos) {400, 900}, SELECTABLE);
    createTextWithLib(VALIDATE, (Arc::Pos) {1300, 900}, SELECTABLE);
    if (this->gameData.textSet.size() > 1) {
        this->gameData.textSet[IDX_LIST_START].color = Arc::Color::YELLOW;
    }
    createTextWithLib("", (Arc::Pos) {550, 900}, NOT_SELECTABLE);
}

void Arc::Menu::defineIdxCursor()
{
    std::size_t indexText = 0;

    for (const auto &text : this->gameData.textSet) {
        if (getFileName(text.text) == "arcade_menu.so") {
            break;
        }
        ++indexText;
    }
    _cursorPlace = {
        .elemInSelect = 0,
        .gameLib = indexText - IDX_LIST_START,
        .graphicalLib = 25
    };
}
