/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snake
*/

#include "Snake.hpp"

extern "C"
{
    Arc::IGameModule *entryPoint(void)
    {
        return new Arc::Snake();
    }
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
}

Arc::Snake::~Snake()
{
    appendScore();
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_snake";
        return name;
    }
}
