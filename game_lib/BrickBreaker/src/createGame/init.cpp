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

void Arc::BrickBreaker::createLifeGame()
{
    createBall();
    this->gameData.item.at(1).tile.pos = Arc::Pos(300, 190);
    createBall();
    this->gameData.item.at(2).tile.pos = Arc::Pos(350, 190);
    createBall();
    this->gameData.item.at(3).tile.pos = Arc::Pos(400, 190);
}

Arc::BrickBreaker::BrickBreaker()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    this->gameData.player.health = 3;
    _velocity = {getRandomPos(-5, 5), 8};
    _velocity.x = 5;
    initBricks();
    initUsername();
    createMap();
    createAllTexts();
    createLifeGame();
    _iniPosBall = this->gameData.item.at(0).tile.pos;
    /*
        _clockMove.setCooldown(std::chrono::milliseconds(100));
        _clockMove.start();
    */
}
