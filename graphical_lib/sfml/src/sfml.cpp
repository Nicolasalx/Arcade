/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sfml
*/

#include <iostream>
#include "Sfml.hpp"
#include "DisplayException.hpp"
#include <csignal>

static void abort_sfml(int)
{
    throw Arc::DisplayException("sfml fail to create window.");
}

Arc::Sfml::Sfml()
{
    std::signal(SIGABRT, abort_sfml);
}

extern "C"
{
    Arc::IDisplayModule *entryPoint(void)
    {
        return new Arc::Sfml();
    }
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_D_sfml";
        return name;
    }
}
