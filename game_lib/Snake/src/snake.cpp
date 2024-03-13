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
    Arc::IGameModule *entryPoint(void)
    {
        std::cout << "entry point Snake !\n";
        return new Arc::Snake();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Snake unloaded !\n";
}

Arc::Snake::Snake()
{
    std::cout << "Snake is class constructed.\n";
    
}

Arc::Snake::~Snake()
{
    std::cout << "Snake is class destroyed.\n";
}

void Arc::Snake::init()
{
    std::cout << "Snake is init.\n";
}

void Arc::Snake::stop()
{
    std::cout << "Snake is stopped.\n";
}

const Arc::GameData &Arc::Snake::update(const std::vector<Arc::Event> &)
{
    std::cout << "Update Pacman ...\n";
    return this->gameData;
}

const std::string &Arc::Snake::getName() const
{
    return this->name;
}
