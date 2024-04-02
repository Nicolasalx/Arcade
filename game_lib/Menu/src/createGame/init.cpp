/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** init
*/

#include "Menu.hpp"
#include "getFileContent.hpp"
#include "split_string.hpp"

void Arc::Menu::fillLeaderBoard(std::vector<std::pair<std::string, int>> &linesLexing, std::vector<std::string> &allGame)
{
    std::vector<std::string> tmpContent;
    std::pair<std::string, int> tmpLine;

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

std::vector<std::pair<std::string, int>> Arc::Menu::getAllScore(const std::string &filepath)
{
    std::vector<std::string> allGame = Arc::FileContent::getContent(filepath);
    std::vector<std::pair<std::string, int>> linesLexing;
    std::vector<std::pair<std::string, int>> resultLines;
    size_t indexLeaderBoard = 0;

    fillLeaderBoard(linesLexing, allGame);
    std::sort(linesLexing.begin(), linesLexing.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    for (const auto &lines : linesLexing) {
        if (indexLeaderBoard == 3) {
            break;
        }
        resultLines.push_back(lines);
        ++indexLeaderBoard;
    }
    return resultLines;
}

#include <iostream>

void Arc::Menu::createLeaderBoard()
{
    Pos pos = {0, 0};
    std::size_t indexLeaderBoard = 1;

    _allScore._snakeScore = getAllScore("./game_src/snake/snakeScore.txt");
    _allScore._nibblerScore = getAllScore("game_src/nibbler/nibblerScore.txt");
    _allScore._brickBreakerScore = getAllScore("game_src/brickBreaker/brickBreakerScore.txt");

    createTextWithLib("LEADER BOARD", (Arc::Pos) {1480, 100}, NOT_SELECTABLE);
    createTextWithLib("SNAKE", (Arc::Pos) {1520, 200}, NOT_SELECTABLE);
    pos = {1400, 220};
    for (const auto &snake: _allScore._snakeScore) {
        createTextWithLib(std::to_string(indexLeaderBoard) + ". " + snake.first + " -> " + std::to_string(snake.second) + "pts", (Arc::Pos) {pos.x, pos.y += 50}, NOT_SELECTABLE);
        ++indexLeaderBoard;
    }
    pos = {1400, 430};
    indexLeaderBoard = 1;
    createTextWithLib("NIBBLER", (Arc::Pos) {1515, 430}, NOT_SELECTABLE);
    for (const auto &nibbler: _allScore._nibblerScore) {
        createTextWithLib(std::to_string(indexLeaderBoard) + ". " + nibbler.first + " -> " + std::to_string(nibbler.second) + "pts", (Arc::Pos) {pos.x, pos.y += 50}, NOT_SELECTABLE);
        ++indexLeaderBoard;
    }
    pos = {1400, 640};
    indexLeaderBoard = 1;
    createTextWithLib("BRICK BREAKER", (Arc::Pos) {1490, 640}, NOT_SELECTABLE);
    for (const auto &brickBreaker: _allScore._brickBreakerScore) {
        createTextWithLib(std::to_string(indexLeaderBoard) + ". " + brickBreaker.first + " -> " + std::to_string(brickBreaker.second) + "pts", (Arc::Pos) {pos.x, pos.y += 50}, NOT_SELECTABLE);
        ++indexLeaderBoard;
    }
}

void Arc::Menu::createAllText()
{
    double posY = 250;

    createTextWithLib(GAME_LIST, (Arc::Pos) {200, 200}, NOT_SELECTABLE);
    createTextWithLib(GRAPHICAL_LIST, (Arc::Pos) {600, 200}, NOT_SELECTABLE);
    for (const auto &libGame : this->gameData.lib.game) {
        createTextWithLib(libGame.path, (Arc::Pos) {200, posY += 50}, SELECTABLE);
    }
    posY = 250;
    for (const auto &libGraphical : this->gameData.lib.graphical) {
        createTextWithLib(libGraphical.path, (Arc::Pos) {600, posY += 50}, SELECTABLE);
    }
    createTextWithLib(USERNAME, (Arc::Pos) {400, 900}, SELECTABLE);
    createTextWithLib(VALIDATE, (Arc::Pos) {1300, 900}, SELECTABLE);
    if (this->gameData.textSet.size() > 1) {
        this->gameData.textSet[IDX_LIST_START].color = Arc::Color::YELLOW;
    }
    createLeaderBoard();
    createTextWithLib("", (Arc::Pos) {550, 900}, NOT_SELECTABLE);
}

void Arc::Menu::defineIdxCursor()
{
    std::size_t indexText = 0;

    if (this->gameData.textSet.size() > 0) {
        for (const auto &text : this->gameData.textSet) {
            if (text.text.ends_with("arcade_menu.so")) {
                break;
            }
            ++indexText;
        }
    }
    _cursorPlace = {
        .elemInSelect = 0,
        .gameLib = indexText - IDX_LIST_START,
        .graphicalLib = 25
    };
}
