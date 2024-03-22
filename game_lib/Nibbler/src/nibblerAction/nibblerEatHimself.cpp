/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snakeEatHimself
*/

#include "Nibbler.hpp"

void Arc::Nibbler::isSnakeEatHimself()
{
    Rect snakeHeadRect;
    Rect snakePartRect;

    if (this->gameData.player.health == 0) {
        return;
    }
    if (_nbApple == 10) {
        initEndGame();
        return;
    }
    if (_nbApple < 1) {
        return;
    }
    snakeHeadRect = calculateRect(this->gameData.player.tileSet.at(0).pos, 30);
    for (std::size_t i = 0; i < this->gameData.player.tileSet.size(); ++i) {
        if (i != 0) {
            snakePartRect = calculateRect(this->gameData.player.tileSet.at(i).pos, 30);
            if (areaRectsInContact(snakeHeadRect, snakePartRect)) {
                initEndGame();
                return;
            }
        }
    }
}
