/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Menu
*/

#include <iostream>
#include "Menu.hpp"

extern "C"
{
    Arc::IGameModule *entryPoint(void)
    {
        return new Arc::Menu();
    }
}

Arc::Menu::Menu()
{
    getLibFromDirectory();
    createAllText();
    defineIdxCursor();
}

Arc::Menu::~Menu()
{
    setDefaultName();
}

const Arc::GameData &Arc::Menu::update(const Arc::Event &event)
{
    for (const auto &evt : event.eventType) {
        switch (evt) {
            case Arc::EventType::DOWN:
                selectNextChoice();
            break;
            case Arc::EventType::UP:
                selectPrevChoice();
            break;
            case Arc::EventType::ENTER:
                validateChoice(_allTextSelectable[_cursorPlace.elemInSelect].text);
            break;
            default:
                break;
        }
    }
    fillUsername(event.buffer);
    modifyAllTextColor();
    return this->gameData;
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_menu";
        return name;
    }
}
