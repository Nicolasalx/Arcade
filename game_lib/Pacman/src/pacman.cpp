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
        std::cout << "entry point Pacman !\n";
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

const std::string &Arc::Pacman::getName() const
{
    return this->name;
}
