/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** modifyChoice
*/

#include "Menu.hpp"

void Arc::Menu::selectNextChoice()
{
    if (_cursorPlace.elemInSelect + 1 > _allTextSelectable.size() - 1) {
        _cursorPlace.elemInSelect = 0;
    } else {
        _cursorPlace.elemInSelect += 1;
    }
}

void Arc::Menu::modifyAllTextColor(void)
{
    std::size_t indexText = IDX_LIST_START;

    for (const auto &textSelectable : _allTextSelectable) {
        if (textSelectable.text == _allTextSelectable[_cursorPlace.elemInSelect].text) {
            this->gameData.textSet[indexText].color = Arc::Color::YELLOW;
        } else if (textSelectable.text == _allTextSelectable[_cursorPlace.gameLib].text) {
            this->gameData.textSet[indexText].color = Arc::Color::BLUE;
        } else if (_cursorPlace.graphicalLib < _allTextSelectable.size() && textSelectable.text == _allTextSelectable[_cursorPlace.graphicalLib].text) {
            this->gameData.textSet[indexText].color = Arc::Color::BLUE;
        } else {
            this->gameData.textSet[indexText].color = Arc::Color::WHITE;
        }
        ++indexText;
    }
}

void Arc::Menu::selectPrevChoice(void)
{
    if (_cursorPlace.elemInSelect == 0) {
        _cursorPlace.elemInSelect = _allTextSelectable.size() - 1;
    } else {
        _cursorPlace.elemInSelect -= 1;
    }
}
