/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** endOfTheGame
*/

#include "Nibbler.hpp"

void Arc::Nibbler::initEndGame()
{
    this->gameData.textSet.clear();
    this->gameData.tileSet.clear();
    this->gameData.player.tileSet.clear();
    this->gameData.item.clear();
    this->gameData.player.health = 0;

    createText("You loose !" + this->gameData.player.userName, Arc::Pos(860, 200), Arc::Color::RED);
    createText("You score: " + std::to_string(_actualScore), Arc::Pos(860, 300), Arc::Color::CYAN);
    createText("The highscore is: " + std::to_string(_highScore), Arc::Pos(820, 400), Arc::Color::YELLOW);

    createText("\\       N   N  IIIII  BBBBB  BBBBB  LL     EEEE  RRRR       /", Arc::Pos(620, 600), Arc::Color::MAGENTA);
    createText(" \\      NN  N    I    B   B  B   B  LL     E     R   R     / ", Arc::Pos(620, 620), Arc::Color::MAGENTA);
    createText("  \\     N N N    I    BBBB   BBBB   LL     EEEE  RRRR     /  ", Arc::Pos(620, 640), Arc::Color::MAGENTA);
    createText("   \\    N  NN    I    B   B  B   B  LL     E     R R     /   ", Arc::Pos(620, 660), Arc::Color::MAGENTA);
    createText("    \\   N   N  IIIII  BBBBB  BBBBB  LLLLLL EEEE  R  R   /    ", Arc::Pos(620, 680), Arc::Color::MAGENTA);

    createText("PRESS 'R' FOR RESTART", Arc::Pos(840, 840), Arc::Color::WHITE);
    createText("PRESS 'M' TO GO BACK ON MENU", Arc::Pos(800, 900), Arc::Color::WHITE);
}

void Arc::Nibbler::endTheGame()
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
