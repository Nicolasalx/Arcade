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

    createText("You loose !", Arc::Pos(460, 200), Arc::Color::RED);
    createText("You score: " + std::to_string(_actualScore), Arc::Pos(460, 300), Arc::Color::CYAN);
    createText("The highscore is: " + std::to_string(_highScore), Arc::Pos(420, 400), Arc::Color::YELLOW);

    createText("\\       SSSS  N   N  AAAAA K  K  EEEE       /", Arc::Pos(280, 600), Arc::Color::MAGENTA);
    createText(" \\     S      NN  N  A   A K K   E         / ", Arc::Pos(280, 620), Arc::Color::MAGENTA);
    createText("  \\     SSSS  N N N  AAAAA KK    EEEE     /  ", Arc::Pos(280, 640), Arc::Color::MAGENTA);
    createText("   \\        S N  NN  A   A K K   E       /   ", Arc::Pos(280, 660), Arc::Color::MAGENTA);
    createText("    \\   SSSS  N   N  A   A K  K  EEEE   /    ", Arc::Pos(280, 680), Arc::Color::MAGENTA);

    createText("PRESS 'R' FOR RESTART", Arc::Pos(840, 840), Arc::Color::WHITE);
    createText("PRESS 'M' TO GO BACK ON MENU", Arc::Pos(800, 900), Arc::Color::WHITE);

    createLeaderBoard();
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
