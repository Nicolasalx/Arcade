/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Ncurses
*/

#include <iostream>
#include "Ncurses.hpp"

extern "C"
{
    Arc::IDisplayModule *entryPoint(void)
    {
        return new Arc::Ncurses();
    }
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_D_ncurses";
        return name;
    }
}
