/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Sdl2
*/

#include <iostream>
#include "Sdl2.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "Sdl2 loaded !\n";
}

extern "C"
{
    Arc::IDisplayModule *entryPoint(void)
    {
        return new Arc::Sdl2();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Sdl2 unloaded !\n";
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_D_sdl2";
        return name;
    }
}
