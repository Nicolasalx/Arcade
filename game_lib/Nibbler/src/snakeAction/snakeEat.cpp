/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snakeEat
*/

#include "Nibbler.hpp"

void Arc::Nibbler::snakeEatAFood()
{
    Pos tail;
    Rect snakeHeadRect = calculateRect(this->gameData.player.tileSet.at(0).pos, 39);
    Rect itemRect = calculateRect(this->gameData.item.at(0).pos, 39);
    SnakeMove snakeMove;

    if (areaRectsInContact(snakeHeadRect, itemRect)) {
        _actualScore += 1;
        this->gameData.textSet.at(1).text = "Actual score: " + std::to_string(_actualScore);
        this->gameData.item.at(0).pos = computeNewSizeItem();
        this->gameData.item.at(0).tile.pos = this->gameData.item.at(0).pos;

        tail = this->gameData.player.tileSet.back().pos;
        createPlayer(tail, Arc::Size(40, 40), SNAKE_TAIL);
    }
}
