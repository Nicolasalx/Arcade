/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** init
*/

#include "BrickBreaker.hpp"

void Arc::BrickBreaker::initBricks()
{
    Enemy enemy;
    this->gameData.enemy.push_back(enemy);
}

Arc::BrickBreaker::BrickBreaker()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    this->gameData.player.health = 3;
    _velocity = {getRandomPos(-5, 5), 8};
    initBricks();
    initUsername();
    createMap();
    createAllTexts();
    /*
        _clockMove.setCooldown(std::chrono::milliseconds(100));
        _clockMove.start();
    */
}
