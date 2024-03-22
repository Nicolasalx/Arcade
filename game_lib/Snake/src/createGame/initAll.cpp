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

void Arc::Snake::initHighScore()
{
    std::vector<std::string> tokensByLine = Arc::FileContent::getContent("./game_src/snake/snakeScore.txt");
    std::vector<std::string> stockLines;

    for (const auto &line : tokensByLine) {
        stockLines.clear();
        my::split_string(line, ":", stockLines);
        if (stockLines.size() == 2) {
            std::size_t newScore = std::stoi(stockLines[1]);
            if (newScore > _highScore) {
                _highScore = newScore;
            }
        }
    }
}

void Arc::Snake::initUsername()
{
    std::vector<std::string> tokensByLine = Arc::FileContent::getContent("./game_src/username.txt");

    if (tokensByLine.size() > 0) {
        this->gameData.player.userName = tokensByLine.at(0);
    }
}

