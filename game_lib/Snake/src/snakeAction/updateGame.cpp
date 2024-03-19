/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** updateGame
*/

#include "Snake.hpp"
#include "getFileContent.hpp"

void Arc::Snake::checkHighScore()
{
    std::string content;

    if (_actualScore > _highScore) {
        ++_highScore;
        this->gameData.textSet.at(2).text = "High score: " + std::to_string(_highScore);
        content = this->gameData.player.userName + "\n" + std::to_string(_highScore);
        Arc::FileContent::printContentToFile("./score/snakeScore.txt", content);
    }
}

const Arc::GameData &Arc::Snake::update(const Arc::Event &event)
{
    endTheGame();
    if (this->gameData.player.health == 0) {
        return this->gameData;
    }
    for (const auto &evt : event.eventType) {
        switch (evt) {
            case Arc::EventType::UP:
                changeDirection(UP);
            break;
            case Arc::EventType::DOWN:
                changeDirection(DOWN);
            break;
            case Arc::EventType::LEFT:
                changeDirection(LEFT);
            break;
            case Arc::EventType::RIGHT:
                changeDirection(RIGHT);
            break;
            default:
            break;
        }
    }
    moveNextCase();
    checkHighScore();
    snakeEatAFood();
    isSnakeEatHimself();
    return this->gameData;
}
