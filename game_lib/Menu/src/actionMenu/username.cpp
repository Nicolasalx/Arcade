/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** username
*/

#include "Menu.hpp"
#include "getFileContent.hpp"

void Arc::Menu::handleActionUsername(const std::string &filename)
{
    if (filename == USERNAME) {
        if (this->gameData.player.userName.length() == 0) {
            this->gameData.player.ignoreKey = true;
        } else {
            Arc::FileContent::truncContentToFile("./game_src/username.txt", this->gameData.player.userName);
            this->gameData.player.ignoreKey = false;
        }
        return;
    }
    handleValidation(filename);
}

void Arc::Menu::detectDelete(const std::string &bufferEvent, bool &isADeleteChar)
{
    for (const auto &buff : bufferEvent) {
        if (buff == 8) {
            isADeleteChar = true;
            break;
        }
    }
}

void Arc::Menu::fillUsername(const std::string &bufferEvent)
{
    bool isADeleteChar = false;

    if (this->gameData.player.ignoreKey) {
        detectDelete(bufferEvent, isADeleteChar);
        if (!isADeleteChar) {
            this->gameData.player.userName += bufferEvent;
        } else if (isADeleteChar && !this->gameData.player.userName.empty()) {
            this->gameData.player.userName.pop_back();
        }
        this->gameData.textSet.at(this->gameData.textSet.size() - 1).text = this->gameData.player.userName;
    }
}
