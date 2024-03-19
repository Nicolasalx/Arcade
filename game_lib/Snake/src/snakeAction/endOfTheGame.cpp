/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** endOfTheGame
*/

#include "Snake.hpp"

void Arc::Snake::initEndGame()
{
    this->gameData.textSet.clear();
    this->gameData.tileSet.clear();
    this->gameData.player.tileSet.clear();
    this->gameData.item.clear();
    this->gameData.player.health = 0;

    createText("You loose !" + this->gameData.player.userName, Arc::Pos(800, 300));
    createText("You score: " + std::to_string(_actualScore), Arc::Pos(800, 600));
    createText("The highscore is: " + std::to_string(_highScore), Arc::Pos(800, 800));
}

void Arc::Snake::endTheGame()
{
    if (this->gameData.player.health == 0) {
        return;
    }
    for (const auto &part : this->gameData.player.tileSet) {
        if (part.pos.x <= 500 || part.pos.x >= 1260 ||
            part.pos.y <= 100 || part.pos.y >= 860) {
            initEndGame();
            return;
        }
    }
    isSnakeEatHimself();
}
