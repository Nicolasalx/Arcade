/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snake
*/

#include <iostream>
#include "Menu.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "Menu loaded !\n";
}

extern "C"
{
    Arc::IGameModule *entryPoint(void)
    {
        std::cout << "entry point Menu !\n";
        return new Arc::Menu();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Menu unloaded !\n";
}

Arc::Menu::Menu()
{
    std::cout << "Menu is class constructed.\n";
}

Arc::Menu::~Menu()
{
    std::cout << "Menu is class destroyed.\n";
}

void Arc::Menu::createTextWithLib(const std::string &name, size_t &posY)
{
    Arc::Text text;

    text.text = name;
    text.color = Arc::Color::RED;
    text.fontPath = "fonts/heavitas.ttf";
    text.pos = {100, posY += 50};
    this->gameData.textSet.push_back(text);
}

void Arc::Menu::getLibFromDirectory()
{
    std::string filename;

    for (const auto &entry : std::filesystem::directory_iterator("./lib/")) {
        filename = entry.path().filename().string();
        if (_allLibGame.contains(filename)) {
            _mapLibGame.insert(filename);
        }
        if (_allLibGraphical.contains(filename)) {
            _mapLibGraphical.insert(filename);
        }
    }
}

const Arc::GameData Arc::Menu::init()
{
    size_t posY = 0;

    _cursorPlace = {"arcade_menu.so", "arcade_menu.so"};
    getLibFromDirectory();
    createTextWithLib("Games list:", posY);
    createTextWithLib("Graphicals list:", posY);
    createTextWithLib("Username:", posY);
    for (const auto &libGame : _mapLibGame) {
        createTextWithLib(libGame, posY);
    }
    for (const auto &libGraphical : _mapLibGraphical) {
        createTextWithLib(libGraphical, posY);
    }
    return this->gameData;
}

void Arc::Menu::stop()
{
    std::cout << "Menu is stopped.\n";
}

const Arc::GameData &Arc::Menu::update(const std::vector<Arc::Event> &event)
{
    std::cout << "Update Menu ...\n";
    return this->gameData;
}

const std::string &Arc::Menu::getName() const
{
    return this->_name;
}
