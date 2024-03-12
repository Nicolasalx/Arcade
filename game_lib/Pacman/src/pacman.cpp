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
    IDisplayModule *entryPoint(void)
    {
        std::cout << "entry point Pacman !\n";
        return new Pacman();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Pacman unloaded !\n";
}

Pacman::Pacman()
{
    std::cout << "Pacman is class constructed.\n";
}

Pacman::~Pacman()
{
    std::cout << "Pacman is class destroyed.\n";
}

void Pacman::init()
{
    std::cout << "Pacman is init.\n";
}

void Pacman::stop()
{
    std::cout << "Pacman is stopped.\n";
}

const std::string &Pacman::getName() const
{
    return this->name;
}
