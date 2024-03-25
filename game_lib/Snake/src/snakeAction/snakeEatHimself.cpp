/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snakeEatHimself
*/

#include "Snake.hpp"

void Arc::Snake::checkLooseSnake(std::size_t i, Rect snakeHeadRect, Rect snakePartRect)
{
    if (i != 0) {
        snakePartRect = calculateRect(this->gameData.player.tileSet.at(i).pos, 30);
        if (areaRectsInContact(snakeHeadRect, snakePartRect)) {
            initEndGame();
            return;
        }
    }
}

void Arc::Snake::isSnakeEatHimself()
{
    Rect snakeHeadRect;
    Rect snakePartRect;

    if (_actualScore < 5) {
        return;
    }
    snakeHeadRect = calculateRect(this->gameData.player.tileSet.at(0).pos, 30);
    for (std::size_t i = 0; i < this->gameData.player.tileSet.size(); ++i) {
        checkLooseSnake(i, snakeHeadRect, snakePartRect);
    }
}
