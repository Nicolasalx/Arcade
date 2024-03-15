/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** pacman
*/

#include <iostream>
#include "Pacman.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "Pacman loaded !\n";
}

extern "C"
{
    Arc::IGameModule *entryPoint(void)
    {
        return new Arc::Pacman();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Pacman unloaded !\n";
}

Arc::Pacman::Pacman()
{
    std::cout << "Pacman is class constructed.\n";
}

Arc::Pacman::~Pacman()
{
    std::cout << "Pacman is class destroyed.\n";
}

void Arc::Pacman::init()
{
    std::cout << "Pacman is init.\n";
}

void Arc::Pacman::stop()
{
    std::cout << "Pacman is stopped.\n";
}

const Arc::GameData &Arc::Pacman::update(const Arc::Event &)
{
    std::cout << "Update Pacman ...\n";
    return this->gameData;
}

const std::string &Arc::Pacman::getName() const
{
    return this->_name;
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_pacman";
        return name;
    }
}
