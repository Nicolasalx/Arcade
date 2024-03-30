/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** updateGame
*/

#include "BrickBreaker.hpp"
#include "getFileContent.hpp"

void Arc::BrickBreaker::switchDirEvent(const Arc::Event &event)
{
    for (const auto &evt : event.eventType) {
        switch (evt) {
            case Arc::EventType::LEFT:
                moovePlayerLeft();
            break;
            case Arc::EventType::RIGHT:
                moovePlayerRight();
            break;
            default:
            break;
        }
    }
}

void Arc::BrickBreaker::appendScore()
{
    std::string content;

    content = this->gameData.player.userName + ":" + std::to_string(_actualScore) + "\n";
    Arc::FileContent::appendContentToFile("./game_src/brickBreaker/brickBreakerScore.txt", content);
}

void Arc::BrickBreaker::checkHighScore()
{
    if (_actualScore > _highScore) {
        ++_highScore;
        this->gameData.textSet.at(2).text = "High score: " + std::to_string(_highScore);
    }
}

void Arc::BrickBreaker::checkPlayerWin()
{
    bool playerWin = true;

    for (const auto &brick: this->gameData.enemy.at(0).tileSet) {
        if (brick.pos.x < 10000) {
            playerWin = false;
        }
    }
    if (playerWin == true) {
        this->gameData.player.health = 50;
    }
}

const Arc::GameData &Arc::BrickBreaker::update(const Arc::Event &event)
{
    if (this->gameData.player.health == 0) {
        return this->gameData;
    }
    switchDirEvent(event);
    mooveRight();
    mooveLeft();

    mooveBall();
    checkHighScore();
    updateText();
    checkPlayerWin();
    playerLooseOneLife();
    checkEndGame();
    return this->gameData;
}
