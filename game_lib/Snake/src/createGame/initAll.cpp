/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** initAll
*/

#include "Snake.hpp"
#include "GameException.hpp"
#include "getFileContent.hpp"
#include "split_string.hpp"

void Arc::Snake::setNewHighScore(std::vector<std::string> &stockLines)
{
    std::size_t newScore = 0;

    if (stockLines.size() == 2) {
        newScore = std::stoi(stockLines[1]);
        if (newScore > _highScore) {
            _highScore = newScore;
        }
    }
}

void Arc::Snake::initHighScore()
{
    std::vector<std::string> tokensByLine = Arc::FileContent::getContent("./game_src/snake/snakeScore.txt");
    std::vector<std::string> stockLines;

    for (auto &line : tokensByLine) {
        stockLines.clear();
        my::split_string(line, ":", stockLines);
        setNewHighScore(stockLines);
    }
}

void Arc::Snake::initUsername()
{
    std::vector<std::string> tokensByLine = Arc::FileContent::getContent("./game_src/username.txt");

    if (!tokensByLine.empty()) {
        this->gameData.player.userName = tokensByLine.at(0);
    }
}

