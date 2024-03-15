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

void Arc::Menu::createTextWithLib(const std::string &name, Pos pos)
{
    Arc::Text text;

    text.text = name;
    text.color = Arc::Color::RED;
    text.fontPath = "fonts/DroidSansMono.ttf";
    text.pos = {pos.x, pos.y};
    text.size = 20;
    this->gameData.textSet.push_back(text);
    this->_allText.push_back(text);
}

void Arc::Menu::selectTypeLib(const std::string &filename)
{
    Arc::DLLoader<void> libLoader;
    std::string nameLib;

    try {
        libLoader.load("./lib/" + filename);
        nameLib = libLoader.getName();
    } catch (const std::exception &e) {
        return;
    }

    if (nameLib.find("arcade_G") != std::string::npos) {
        _mapLibGame.push_back(filename);
    }
    if (nameLib.find("arcade_D") != std::string::npos) {
        _mapLibGraphical.push_back(filename);
    }
}

void Arc::Menu::getLibFromDirectory()
{
    std::string filename;

    for (const auto &entry : std::filesystem::directory_iterator("./lib/")) {
        filename = entry.path().filename().string();
        selectTypeLib(filename);
    }
}

void Arc::Menu::init()
{
    double posY = 250;

    getLibFromDirectory();

    createTextWithLib("Games list:", (Arc::Pos) {500, 200});
    for (const auto &libGame : _mapLibGame) {
        createTextWithLib(libGame, (Arc::Pos) {500, posY += 50});
    }

    posY = 250;
    createTextWithLib("Graphicals list:", (Arc::Pos) {1100, 200});
    for (const auto &libGraphical : _mapLibGraphical) {
        createTextWithLib(libGraphical, (Arc::Pos) {1100, posY += 50});
    }
    createTextWithLib("Username", (Arc::Pos) {400, 900});
    createTextWithLib("Valider", (Arc::Pos) {1300, 900});
}

void Arc::Menu::stop()
{
    std::cerr << "Menu is stopped.\n";
}

const Arc::GameData &Arc::Menu::update(const Arc::Event &)
{
    return this->gameData;
}

const std::string &Arc::Menu::getName() const
{
    return this->_name;
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_menu";
        return name;
    }
}
