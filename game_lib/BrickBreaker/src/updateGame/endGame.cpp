/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** endGame
*/

#include "BrickBreaker.hpp"

void Arc::BrickBreaker::initEndGame()
{
    this->gameData.textSet.clear();
    this->gameData.tileSet.clear();
    this->gameData.player.tileSet.clear();
    this->gameData.item.clear();
    this->gameData.enemy.clear();
}

void Arc::BrickBreaker::checkEndGame()
{
    if (this->gameData.player.health == 0) {
        initEndGame();
    }
}

void Arc::BrickBreaker::playerLooseOneLife()
{
    if (this->gameData.item.at(0).tile.pos.y > 1080) {
        this->gameData.item.at(this->gameData.player.health).tile.pos.x = 10000;
        this->gameData.player.health -= 1;
        this->gameData.item.at(0).tile.pos = _iniPosBall;
        _velocity.y = -_velocity.y;
    }
}
