/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** moovePlayer
*/

#include "BrickBreaker.hpp"

void Arc::BrickBreaker::moovePlayerLeft()
{
    if (this->gameData.player.tileSet.at(0).pos.x >= X_POS_MAP + (SIZE_BORDER * 2)) {
        this->gameData.player.tileSet.at(0).pos.x -= SIZE_BORDER;
    }
}

void Arc::BrickBreaker::moovePlayerRight()
{
    if (this->gameData.player.tileSet.at(0).pos.x <= X_POS_MAP + (SIZE_BORDER * 10)) {
        this->gameData.player.tileSet.at(0).pos.x += SIZE_BORDER;
    }
}
