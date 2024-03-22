/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** randomPosApple
*/

#include "Nibbler.hpp"

double Arc::Nibbler::getRandomPos(double min, double max)
{
    double randomValue = min + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX) / (max - min));
    double remainder = std::fmod(randomValue, 40.0);

    if (remainder != 0) {
        randomValue += 40.0 - remainder;
    }
    return randomValue;
}

bool Arc::Nibbler::appleIsOnApple(Rect appleRect, Rect snakePartRect)
{
    for (const auto &part : this->gameData.item) {
        snakePartRect = calculateRect(part.pos, 30);
        if (areaRectsInContact(appleRect, snakePartRect)) {
            return true;
        }
    }
    return false;
}

bool Arc::Nibbler::checkWall(Arc::Tile &part, Rect snakePartRect, Rect appleRect)
{
    if (part.c == '#') {
        snakePartRect = calculateRect(part.pos, 30);
        if (areaRectsInContact(appleRect, snakePartRect)) {
            return true;
        }
    }
    return false;
}

bool Arc::Nibbler::appleIsOnSnake(Pos pos)
{
    Rect appleRect = calculateRect(pos, 30);
    Rect snakePartRect;

    for (const auto &part : this->gameData.player.tileSet) {
        snakePartRect = calculateRect(part.pos, 30);
        if (areaRectsInContact(appleRect, snakePartRect)) {
            return true;
        }
    }
    for (auto &part : this->gameData.tileSet) {
        if (checkWall(part, snakePartRect, appleRect)) {
            return true;
        }
    }
    return appleIsOnApple(appleRect, snakePartRect);
}

Arc::Pos Arc::Nibbler::computeNewSizeItem()
{
    Pos pos;

    pos.x = getRandomPos(0, 720) + 500;
    pos.y = getRandomPos(0, 680) + Y_POS_MAP;
    while (appleIsOnSnake(pos)) {
        pos.x = getRandomPos(0, 720) + 500;
        pos.y = getRandomPos(0, 680) + 100;
    }
    return pos;
}
