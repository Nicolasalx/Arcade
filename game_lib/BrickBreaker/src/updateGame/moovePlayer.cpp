/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** moovePlayer
*/

#include "BrickBreaker.hpp"

void Arc::BrickBreaker::mooveRight()
{
    if (!_clockMove.isElapsed()) {
        return;
    }
    _clockMove.reset();

    if (_rightMoove == true) {
        this->gameData.player.tileSet.at(0).pos.x += 5;
    }
    if (this->gameData.player.tileSet.at(0).pos.x == _posRightStock) {
        _rightMoove = false;
    }
}

void Arc::BrickBreaker::mooveLeft()
{
    if (!_clockEvent.isElapsed()) {
        return;
    }
    _clockEvent.reset();

    if (_leftMoove == true) {
        this->gameData.player.tileSet.at(0).pos.x -= 5;
    }
    if (this->gameData.player.tileSet.at(0).pos.x == _posLeftStock) {
        _leftMoove = false;
    }
}

void Arc::BrickBreaker::moovePlayerLeft()
{
    if (this->gameData.player.tileSet.at(0).pos.x >= X_POS_MAP + (SIZE_BORDER * 2)) {
        _rightMoove = false;
        _leftMoove = true;
        _posLeftStock = this->gameData.player.tileSet.at(0).pos.x - SIZE_BORDER;
    }
}

void Arc::BrickBreaker::moovePlayerRight()
{
    if (this->gameData.player.tileSet.at(0).pos.x <= X_POS_MAP + (SIZE_BORDER * 10)) {
        _rightMoove = true;
        _leftMoove = false;
        _posRightStock = this->gameData.player.tileSet.at(0).pos.x + SIZE_BORDER;
    }
}
