/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** mooveBall
*/

#include "BrickBreaker.hpp"
#include <cmath>

void Arc::BrickBreaker::contactWithBrick(Rect ballRect, Rect partRect)
{
    TypeOfContact result;

    for (auto &tile: this->gameData.enemy.at(0).tileSet) {
        partRect = calculateRect(tile.pos, SIZE_BORDER);
        result = areaRectsWithContactType(ballRect, partRect);
        if (result == HORIZONTAL) {
            _velocity.x = -_velocity.x;
            tile.pos.x = 10000;
            _highScore += 100;
            break;
        } else if (result == VERTICAL) {
            _velocity.y = -_velocity.y;
            tile.pos.x = 10000;
            _highScore += 100;
            break;
        }
    }
}

void Arc::BrickBreaker::contactWithWall(Rect ballRect, Rect partRect)
{
    TypeOfContact result;

    for (const auto &tile: this->gameData.tileSet) {
        partRect = calculateRect(tile.pos, SIZE_BORDER);
        result = areaRectsWithContactType(ballRect, partRect);
        if (result == HORIZONTAL) {
            _velocity.x = -_velocity.x;
            break;
        } else if (result == VERTICAL) {
            _velocity.y = -_velocity.y;
            break;
        }
    }
}

void Arc::BrickBreaker::contactWithPlayer(Rect ballRect, Rect partRect)
{
    for (const auto &tile: this->gameData.player.tileSet) {
        partRect = calculateRect(tile.pos, 120);
        if (areaRectsInContact(ballRect, partRect)) {
            _velocity.y = -_velocity.y;
        }
    }
}

void Arc::BrickBreaker::mooveNextPoint()
{
    this->gameData.item.at(0).tile.pos.x += _velocity.x;
    this->gameData.item.at(0).tile.pos.y += _velocity.y;
}

void Arc::BrickBreaker::mooveBall()
{
    Rect ballRect;
    Rect partRect;

    mooveNextPoint();
    ballRect = calculateRect(this->gameData.item.at(0).tile.pos, 30);
    contactWithPlayer(ballRect, partRect);
    contactWithWall(ballRect, partRect);
    contactWithBrick(ballRect, partRect);
}

