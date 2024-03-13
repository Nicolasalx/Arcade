/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Ncurses
*/

#include <iostream>
#include "Ncurses.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "Ncurses loaded !\n";
}

extern "C"
{
    Arc::IDisplayModule *entryPoint(void)
    {
        std::cout << "entry point Ncurses !\n";
        return new Arc::Ncurses();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Ncurses unloaded !\n";
}

void Arc::Ncurses::init()
{
    std::cout << "Ncurses is init.\n";
}

std::vector<Arc::Event> Arc::Ncurses::getEvent()
{
    std::cout << "Ncurses get event.\n";
    return std::vector<Arc::Event>();
}

void Arc::Ncurses::refresh(const Arc::GameData &gameData)
{
    (void) gameData;
    std::cout << "Refresh Ncurses ...";
}

void Arc::Ncurses::stop()
{
    std::cout << "Ncurses is stopped.\n";
}

const std::string &Arc::Ncurses::getName() const
{
    return this->name;
}
