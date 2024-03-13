/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snake
*/

#include <iostream>
#include "Snake.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "Snake loaded !\n";
}

extern "C"
{
    IDisplayModule *entryPoint(void)
    {
        std::cout << "entry point Snake !\n";
        return new Snake();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Snake unloaded !\n";
}

Snake::Snake()
{
    std::cout << "Snake is class constructed.\n";
}

Snake::~Snake()
{
    std::cout << "Snake is class destroyed.\n";
}

void Snake::init()
{
    std::cout << "Snake is init.\n";
}

void Snake::stop()
{
    std::cout << "Snake is stopped.\n";
}

const std::string &Snake::getName() const
{
    return this->name;
}
