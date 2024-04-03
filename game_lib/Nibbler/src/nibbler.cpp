/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snake
*/

#include "Nibbler.hpp"

extern "C"
{
    Arc::IGameModule *entryPoint(void)
    {
        return new Arc::Nibbler();
    }
}

Arc::Nibbler::Nibbler()
{
    this->gameData.player.health = 100;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    createTile(Arc::Pos(500, 100), Arc::Size(800, SIZE_BORDER), TIME_BAR);

    initHighScore();
    initUsername();
    createAllTexts();
    createMap();
    for (int i = 0; i < NB_ITEM; ++i) {
        createApple();
    }

    _clockMove.setCooldown(std::chrono::milliseconds(100));
    _clockMove.start();

    _clockEvent.setCooldown(std::chrono::milliseconds(50));
    _clockEvent.start();

    _clockGame.setCooldown(std::chrono::milliseconds(TIME_IN_MILI));
    _clockGame.start();
}

Arc::Nibbler::~Nibbler()
{
    appendScore();
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_nibbler";
        return name;
    }
}
