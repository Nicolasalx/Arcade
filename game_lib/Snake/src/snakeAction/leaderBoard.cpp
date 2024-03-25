/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** leaderBoard
*/

#include "Snake.hpp"
#include "getFileContent.hpp"
#include "split_string.hpp"

void Arc::Snake::printLeaderBoard(std::vector<std::pair<std::string, int>> &linesLexing)
{
    std::size_t posY = 200;

    createText("!! LEADER BORD !!", Arc::Pos(1350, 150), Arc::Color::MAGENTA);
    for (const auto& pair : linesLexing) {
        if (posY == 200) {
            createText(pair.first + " --->>> " + std::to_string(pair.second) + " points", Arc::Pos(1350, posY), Arc::Color::GREEN);
        } else {
            createText(pair.first + " --->>> " + std::to_string(pair.second) + " points", Arc::Pos(1350, posY), Arc::Color::YELLOW);
        }
        posY += 50;
    }
}

void Arc::Snake::fillLeaderBoard(std::vector<std::pair<std::string, int>> &linesLexing, std::vector<std::string> &allGame)
{
    std::vector<std::string> tmpContent;
    std::pair<std::string, int> tmpLine;

    tmpLine.first = this->gameData.player.userName;
    tmpLine.second = _actualScore;
    linesLexing.push_back(tmpLine);
    for (const auto &game : allGame) {
        tmpContent.clear();
        my::split_string(game, ":", tmpContent);
        if (tmpContent.size() == 2) {
            tmpLine.first = tmpContent[0];
            tmpLine.second = std::stoi(tmpContent[1]);
            linesLexing.push_back(tmpLine);
        }
    }
}

void Arc::Snake::createLeaderBoard()
{
    std::vector<std::string> allGame = Arc::FileContent::getContent("./game_src/snake/snakeScore.txt");
    std::vector<std::pair<std::string, int>> linesLexing;

    fillLeaderBoard(linesLexing, allGame);
    std::sort(linesLexing.begin(), linesLexing.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    printLeaderBoard(linesLexing);

}