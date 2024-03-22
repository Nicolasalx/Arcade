/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snakeEat
*/

#include "Nibbler.hpp"

void Arc::Nibbler::increaseNibbler(std::size_t i, Rect snakeHeadRect, Pos tail)
{
    Rect itemRect = calculateRect(this->gameData.item.at(i).pos, 39);
    SnakeMoove snakeMoove;

    if (areaRectsInContact(snakeHeadRect, itemRect)) {
        _nbApple += 1;
        this->gameData.item.at(i).pos = Arc::Pos(10000, 10000);
        this->gameData.item.at(i).tile.pos = Arc::Pos(10000, 10000);
        tail = this->gameData.player.tileSet.back().pos;
        createPlayer(tail, Arc::Size(40, 40), SNAKE_TAIL);
        if (std::chrono::milliseconds(_clockGame.getCurrentTime()).count() < TIME_IN_MILI) {
            _clockGame.addTime(std::chrono::milliseconds(1000));
        }
    }
}

void Arc::Nibbler::snakeEatAFood()
{
    Pos tail;
    Rect snakeHeadRect = calculateRect(this->gameData.player.tileSet.at(0).pos, 39);

    for (std::size_t i = 0; i < NB_ITEM; ++i) {
        increaseNibbler(i, snakeHeadRect, tail);
    }
    if (this->gameData.textSet.size() > 2) {
        _actualScore = TIME_IN_MILI - std::chrono::milliseconds(_clockGame.getCurrentTime()).count();
        this->gameData.textSet.at(1).text = "Actual score: " + std::to_string(_actualScore);
    }
}
