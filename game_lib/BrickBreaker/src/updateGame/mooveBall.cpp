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
    TypeOfContact result = NONE;

    for (auto &tile: this->gameData.enemy.at(0).tileSet) {
        partRect = calculateRect(tile.pos, SIZE_BORDER);
        result = areaRectsWithContactType(ballRect, partRect);
        if (result == HORIZONTAL) {
            _velocity.x = -_velocity.x;
            tile.pos.x = 10000;
            _actualScore += 100;
            break;
        } else if (result == VERTICAL) {
            _velocity.y = -_velocity.y;
            tile.pos.x = 10000;
            _actualScore += 100;
            break;
        }
    }
}

void Arc::BrickBreaker::contactWithWall(Rect ballRect, Rect partRect)
{
    TypeOfContact result = NONE;

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
    partRect = calculateRect(this->gameData.player.tileSet.at(0).pos, 120);
    TypeOfContactPlayer typeContact = areaRectsInContact(ballRect, partRect);
    switch (typeContact) {
        case LEFT:
            if (_velocity.x > 0) {
                _velocity.x = -_velocity.x;
            }
            _velocity.y = -_velocity.y;
            break;
        case MIDDLE:
            _velocity.y = -_velocity.y;
            break;
        case RIGHT:
            if (_velocity.x < 0) {
                _velocity.x = -_velocity.x;
            }
            _velocity.y = -_velocity.y;
        case NON:
            break;
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
