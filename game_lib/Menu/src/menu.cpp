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

void Arc::Menu::createTextWithLib(const std::string &libGame, size_t &posY)
{
    Arc::Text text;

    text.text = libGame;
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
        if (allLibGame.find(filename) != allLibGame.end()) {
            mapLibGame.insert(filename);
        }
        if (allLibGraphical.find(filename) != allLibGraphical.end()) {
            mapLibGraphical.insert(filename);
        }
    }
}

const Arc::GameData Arc::Menu::init()
{
    size_t posY = 0;

    getLibFromDirectory();
    for (const auto &libGame : mapLibGame) {
        createTextWithLib(libGame, posY);
    }
    for (const auto &libGraphical : mapLibGraphical) {
        createTextWithLib(libGraphical, posY);
    }
    return this->gameData;
}

void Arc::Menu::stop()
{
    std::cout << "Menu is stopped.\n";
}

const Arc::GameData &Arc::Menu::update(const std::vector<Arc::Event> &)
{
    std::cout << "Update Menu ...\n";
    return this->gameData;
}

const std::string &Arc::Menu::getName() const
{
    return this->_name;
}
