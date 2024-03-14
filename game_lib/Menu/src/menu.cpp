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

void Arc::Menu::init()
{
    /*
        Liste de SfText :
        - Position initialiser
        - Color initialiser

        Open the directory -> List all files
    */

    std::string path = "./lib/";
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        std::string filename = entry.path().filename().string();

        if (allLibGame.find(filename) != allLibGame.end()) {
            mapLibGame.insert(filename);
        }

        if (allLibGraphical.find(filename) != allLibGraphical.end()) {
            mapLibGraphical.insert(filename);
        }
    }

    std::cout << "LIB GAME\n" << "\n";
    for (const auto& element : mapLibGame) {
        std::cout << element << std::endl;
    }

    std::cout << "LIB GRAPHICAL\n" << "\n";
    for (const auto& element : mapLibGraphical) {
        std::cout << element << std::endl;
    }
    std::cout << "Menu is init.\n";
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
