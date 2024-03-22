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
    std::vector<std::string> tokensByLine = Arc::FileContent::getContent("./game_src/nibbler/nibblerScore.txt");

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
