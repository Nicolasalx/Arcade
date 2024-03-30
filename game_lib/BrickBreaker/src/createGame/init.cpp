/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** init
*/

#include "BrickBreaker.hpp"
#include "getFileContent.hpp"
#include "split_string.hpp"

void Arc::BrickBreaker::initBricks()
{
    Enemy enemy;
    this->gameData.enemy.push_back(enemy);
}

void Arc::BrickBreaker::createLifeGame()
{
    createBall();
    this->gameData.item.at(1).tile.pos = Arc::Pos(300, 190);
    createBall();
    this->gameData.item.at(2).tile.pos = Arc::Pos(350, 190);
    createBall();
    this->gameData.item.at(3).tile.pos = Arc::Pos(400, 190);
}

void Arc::BrickBreaker::setNewHighScore(std::vector<std::string> &stockLines)
{
    std::size_t newScore = 0;

    if (stockLines.size() == 2) {
        newScore = std::stoi(stockLines[1]);
        if (newScore > _highScore) {
            _highScore = newScore;
        }
    }
}

void Arc::BrickBreaker::initHighScore()
{
    std::vector<std::string> tokensByLine = Arc::FileContent::getContent("./game_src/brickBreaker/brickBreakerScore.txt");
    std::vector<std::string> stockLines;

    for (auto &line : tokensByLine) {
        stockLines.clear();
        my::split_string(line, ":", stockLines);
        setNewHighScore(stockLines);
    }
}

Arc::BrickBreaker::BrickBreaker()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    this->gameData.player.health = 3;
    _velocity = {getRandomPos(-5, 5), 8};
    _velocity.x = 5;
    initHighScore();
    initBricks();
    initUsername();
    createMap();
    createAllTexts();
    createLifeGame();
    _iniPosBall = this->gameData.item.at(0).tile.pos;
    _clockMove.setCooldown(std::chrono::milliseconds(10));
    _clockMove.start();
    _clockEvent.setCooldown(std::chrono::milliseconds(10));
    _clockEvent.start();
}
