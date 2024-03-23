/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** initUsername
*/

#include "BrickBreaker.hpp"
#include "getFileContent.hpp"

void Arc::BrickBreaker::initUsername()
{
    std::vector<std::string> tokensByLine = Arc::FileContent::getContent("./game_src/username.txt");

    if (!tokensByLine.empty()) {
        this->gameData.player.userName = tokensByLine.at(0);
    }
}
