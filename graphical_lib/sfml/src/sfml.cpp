/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sfml
*/

#include <iostream>
#include "Sfml.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "Sfml loaded !\n";
}

extern "C"
{
    Arc::IDisplayModule *entryPoint(void)
    {
        std::cout << "entry point Sfml !\n";
        return new Arc::Sfml();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Sfml unloaded !\n";
}

void Arc::Sfml::init()
{
    std::cout << "Sfml is init.\n";
}

std::vector<Arc::Event> Arc::Sfml::getEvent()
{
    std::cout << "Sfml get event.\n";
    return std::vector<Arc::Event>();
}

void Arc::Sfml::refresh(const Arc::GameData &gameData)
{
    (void) gameData;
    std::cout << "Refresh Sfml ...";
}

void Arc::Sfml::stop()
{
    std::cout << "Sfml is stopped.\n";
}

const std::string &Arc::Sfml::getName() const
{
    return this->name;
}
