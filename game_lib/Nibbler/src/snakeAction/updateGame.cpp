/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** updateGame
*/

#include "Nibbler.hpp"
#include "getFileContent.hpp"

void Arc::Nibbler::checkHighScore()
{
    std::string content;

    if (_actualScore > _highScore) {
        ++_highScore;
        this->gameData.textSet.at(2).text = "High score: " + std::to_string(_highScore);
        content = this->gameData.player.userName + "\n" + std::to_string(_highScore);
        Arc::FileContent::printContentToFile("./game_src/nibbler/nibblerScore.txt", content);
    }
}

void Arc::Nibbler::animateHead(std::size_t index)
{
    this->gameData.player.tileSet.at(index).c = '1';
    switch (_snake.at(index).nextDirection) {
        case UP:
                this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/headUp.png";
            break;
        case DOWN:
                this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/headDown.png";
            break;
        case LEFT:
                this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/headLeft.png";
            break;
        case RIGHT:
                this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/headRight.png";
            break;
    }
}

void Arc::Nibbler::animateTail(std::size_t index)
{
    this->gameData.player.tileSet.at(index).c = '2';
    switch (_snake.at(index).nextDirection) {
        case UP:
                this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/tailUp.png";
            break;
        case DOWN:
                this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/tailDown.png";
            break;
        case LEFT:
                this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/tailLeft.png";
            break;
        case RIGHT:
                this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/tailRight.png";
            break;
    }
}

void Arc::Nibbler::animateBodyUp(std::size_t index)
{
    switch (_snake.at(index - 1).nextDirection) {
        case UP:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/vertical.png";
            break;
        case DOWN:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/vertical.png";
            break;
        case LEFT:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/topRight.png";
        break;
        case RIGHT:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/topLeft.png";
        break;
    }
}

void Arc::Nibbler::animateBodyDown(std::size_t index)
{
    switch (_snake.at(index - 1).nextDirection) {
        case UP:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/vertical.png";
            break;
        case DOWN:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/vertical.png";
            break;
        case LEFT:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/bottomRight.png";
        break;
        case RIGHT:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/bottomLeft.png";
        break;
    }
}

void Arc::Nibbler::animateBodyLeft(std::size_t index)
{
    switch (_snake.at(index - 1).nextDirection) {
        case RIGHT:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/horizontal.png";
            break;
        case LEFT:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/horizontal.png";
            break;
        case UP:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/bottomLeft.png";
        break;
        case DOWN:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/topLeft.png";
        break;
    }
}

void Arc::Nibbler::animateBodyRight(std::size_t index)
{
    switch (_snake.at(index - 1).nextDirection) {
        case LEFT:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/horizontal.png";
            break;
        case RIGHT:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/horizontal.png";
            break;
        case UP:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/bottomRight.png";
        break;
        case DOWN:
            this->gameData.player.tileSet.at(index).imagePath = std::string(PATH_IMG) + "body/topRight.png";
        break;
    }
}

void Arc::Nibbler::animatePartBody(std::size_t index)
{
    this->gameData.player.tileSet.at(index).c = '=';
    switch (_snake.at(index).nextDirection) {
        case UP:
                animateBodyUp(index);
            break;
        case DOWN:
                animateBodyDown(index);
            break;
        case LEFT:
                animateBodyLeft(index);
            break;
        case RIGHT:
                animateBodyRight(index);
            break;
    }
}

void Arc::Nibbler::animateSnakeBody()
{
    for (std::size_t i = 0; i < this->gameData.player.tileSet.size(); ++i) {
        if (i == 0) {
            animateHead(i);
        } else if (i + 1 == this->gameData.player.tileSet.size()) {
            animateTail(i);
        } else {
            animatePartBody(i);
        }
    }
}

const Arc::GameData &Arc::Nibbler::update(const Arc::Event &event)
{
    isSnakeEatHimself();
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
    animateSnakeBody();
    checkHighScore();
    snakeEatAFood();
    return this->gameData;
}
