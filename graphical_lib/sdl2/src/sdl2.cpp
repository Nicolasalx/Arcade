/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Sdl2
*/

#include "Sdl2.hpp"

extern "C"
{
    Arc::IDisplayModule *entryPoint(void)
    {
        return new Arc::Sdl2();
    }
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_D_sdl2";
        return name;
    }
}
