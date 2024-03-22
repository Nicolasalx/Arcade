/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snake
*/

#include "Snake.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "Snake loaded !\n";
}

extern "C"
{
    Arc::IGameModule *entryPoint(void)
    {
        return new Arc::Snake();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Snake unloaded !\n";
}

Arc::Snake::Snake()
{
    this->gameData.player.health = 100;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    initHighScore();
    initUsername();
    createAllTexts();
    createMap();
    createSnake();
    createApple();

    _clockMove.setCooldown(std::chrono::milliseconds(100));
    _clockMove.start();

    _clockEvent.setCooldown(std::chrono::milliseconds(50));
    _clockEvent.start();
    std::cout << "Snake is class constructed.\n";
}

Arc::Snake::~Snake()
{
    appendScore();
    std::cout << "Snake is class destroyed.\n";
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_snake";
        return name;
    }
}
