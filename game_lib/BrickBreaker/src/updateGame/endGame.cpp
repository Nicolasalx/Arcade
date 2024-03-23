/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** endGame
*/

#include "BrickBreaker.hpp"

void Arc::BrickBreaker::initEndGame()
{
    //createText();
}

void Arc::BrickBreaker::checkEndGame()
{
    if (this->gameData.player.health == 0) {
        initEndGame();
    }
}
