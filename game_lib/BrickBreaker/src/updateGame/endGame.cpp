/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** endGame
*/

#include "BrickBreaker.hpp"

void Arc::BrickBreaker::initEndGame()
{
    this->gameData.textSet.clear();
    this->gameData.tileSet.clear();
    this->gameData.player.tileSet.clear();
    this->gameData.item.clear();
    this->gameData.enemy.clear();

    if (this->gameData.player.health != 0) {
        createText("You WIN !", Arc::Pos(460, 200), Arc::Color::GREEN);
        this->gameData.player.health = 0;
    } else {
        createText("You LOOSE !", Arc::Pos(460, 200), Arc::Color::RED);
    }

    createText("You score: " + std::to_string(_actualScore), Arc::Pos(460, 300), Arc::Color::CYAN);
    createText("The highscore is: " + std::to_string(_highScore), Arc::Pos(420, 400), Arc::Color::YELLOW);

    createText("\\      BBBBB  RRRR   IIIII  CCCC  K  K      BBBBB  RRRR   EEEE  AAAAA  K  K  EEEE  RRRR       /", Arc::Pos(20, 600), Arc::Color::MAGENTA);
    createText(" \\     B   B  R   R    I    C     K K       B   B  R   R  E     A   A  K K   E     R   R     / ", Arc::Pos(20, 620), Arc::Color::MAGENTA);
    createText("  \\    BBBB   RRRR     I    C     KK        BBBB   RRRR   EEEE  AAAAA  KK    EEEE  RRRR     /  ", Arc::Pos(20, 640), Arc::Color::MAGENTA);
    createText("   \\   B   B  R R      I    C     K K       B   B  R R    E     A   A  K K   E     R R     /   ", Arc::Pos(20, 660), Arc::Color::MAGENTA);
    createText("    \\  BBBBB  R  R   IIIII  CCCC  K  K      BBBBB  R  R   EEEE  A   A  K  K  EEEE  R  R   /    ", Arc::Pos(20, 680), Arc::Color::MAGENTA);

    createLeaderBoard();
}

void Arc::BrickBreaker::checkEndGame()
{
    if (this->gameData.player.health == 0 || this->gameData.player.health == 50) {
        initEndGame();
    }
}

void Arc::BrickBreaker::playerLooseOneLife()
{
    if (this->gameData.item.at(0).tile.pos.y > 1080) {
        this->gameData.item.at(this->gameData.player.health).tile.pos.x = 10000;
        this->gameData.player.health -= 1;
        this->gameData.item.at(0).tile.pos = _iniPosBall;
        _velocity.y = -_velocity.y;
    }
}
