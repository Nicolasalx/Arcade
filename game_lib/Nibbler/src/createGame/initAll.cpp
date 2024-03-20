/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** initAll
*/

#include "Nibbler.hpp"
#include "GameException.hpp"
#include "getFileContent.hpp"

void Arc::Nibbler::initHighScore()
{
    std::vector<std::string> tokensByLine = Arc::FileContent::getContent("./game_src/snake/snakeScore.txt");

    if (tokensByLine.size() != 2) {
        throw Arc::GameException("Invalid file high score !");
    }
    _highScore = std::stoi(tokensByLine[1]);
}

void Arc::Nibbler::initUsername()
{
    std::vector<std::string> tokensByLine = Arc::FileContent::getContent("./game_src/username.txt");

    if (tokensByLine.size() > 0) {
        this->gameData.player.userName = tokensByLine.at(0);
    }
}

void Arc::Nibbler::init()
{
    this->gameData.player.health = 100;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    initHighScore();
    initUsername();
    createAllTexts();
    createMap();
    createApple();

    _clockMove.setCooldown(std::chrono::milliseconds(100));
    _clockMove.start();

    _clockEvent.setCooldown(std::chrono::milliseconds(50));
    _clockEvent.start();
}
