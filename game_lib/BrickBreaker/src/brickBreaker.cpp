/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snake
*/

#include "BrickBreaker.hpp"

extern "C"
{
    Arc::IGameModule *entryPoint(void)
    {
        return new Arc::BrickBreaker();
    }
}

Arc::BrickBreaker::~BrickBreaker()
{
    appendScore();
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_brickBreaker";
        return name;
    }
}
