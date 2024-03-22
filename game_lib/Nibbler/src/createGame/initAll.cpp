/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** initAll
*/

#include "Nibbler.hpp"
#include "getFileContent.hpp"
#include "split_string.hpp"

void Arc::Nibbler::setNewHighScore(std::vector<std::string> &stockLines, std::string &line)
{
    std::size_t newScore = 0;

    stockLines.clear();
    my::split_string(line, ":", stockLines);
    if (stockLines.size() == 2) {
        newScore = std::stoi(stockLines[1]);
        if (newScore > _highScore) {
            _highScore = newScore;
        }
    }
}

void Arc::Nibbler::initHighScore()
{
    std::vector<std::string> tokensByLine = Arc::FileContent::getContent("./game_src/nibbler/nibblerScore.txt");
    std::vector<std::string> stockLines;

    for (auto &line : tokensByLine) {
        setNewHighScore(stockLines, line);
    }
}

void Arc::Nibbler::initUsername()
{
    std::vector<std::string> tokensByLine = Arc::FileContent::getContent("./game_src/username.txt");

    if (!tokensByLine.empty()) {
        this->gameData.player.userName = tokensByLine.at(0);
    }
}
