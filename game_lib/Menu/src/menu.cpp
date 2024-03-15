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

void Arc::Menu::createTextWithLib(const std::string &name, double &posY)
{
    Arc::Text text;

    text.text = name;
    text.color = Arc::Color::RED;
    text.fontPath = "fonts/DroidSansMono.ttf";
    text.pos = {100, posY += 50};
    text.size = 20;
    this->gameData.textSet.push_back(text);
}

void Arc::Menu::selectTypeLib(const std::string &filename)
{
    Arc::DLLoader<void> libLoader;
    std::string nameLib;

    try {
        libLoader.load(filename);
        nameLib = libLoader.getName();
    } catch (const std::exception& e) {
        return;
    }

    std::cout << "HERE NAME LIB: " << nameLib << "\n";

    if (filename.find("arcade") == std::string::npos) {
        return;
    }
    if (filename.find("D") != std::string::npos) {
        _mapLibGame.insert(filename);
    }
    if (filename.find("G") != std::string::npos) {
        _mapLibGraphical.insert(filename);
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
    double posY = 0;

    getLibFromDirectory();
    
    //createTextWithLib("Games list:", posY);
    //createTextWithLib("Graphicals list:", posY);
    //createTextWithLib("Username:", posY);
    //for (const auto &libGame : _mapLibGame) {
    //    createTextWithLib(libGame, posY);
    //}
    //for (const auto &libGraphical : _mapLibGraphical) {
    //    createTextWithLib(libGraphical, posY);
    //}
}

void Arc::Menu::stop()
{
    std::cerr << "Menu is stopped.\n";
}

const Arc::GameData &Arc::Menu::update(const std::vector<Arc::Event> &)
{
    return this->gameData;
}

const std::string &Arc::Menu::getName() const
{
    return this->_name;
}

extern "C"
{
    const char *getName()
    {
        static const char name[] = "arcade_G_menu";
        return name;
    }
}
