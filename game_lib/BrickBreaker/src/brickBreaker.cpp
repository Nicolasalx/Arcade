/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snake
*/

#include "BrickBreaker.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "BrickBreaker loaded !\n";
}

extern "C"
{
    Arc::IGameModule *entryPoint(void)
    {
        return new Arc::BrickBreaker();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "BrickBreaker unloaded !\n";
}

Arc::BrickBreaker::~BrickBreaker()
{
    appendScore();
    std::cout << "BrickBreaker is class destroyed.\n";
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_brickBreaker";
        return name;
    }
}
