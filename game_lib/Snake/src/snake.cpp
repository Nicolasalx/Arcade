/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snake
*/

#include "Snake.hpp"
#include "getFileContent.hpp"

// TODO
/*
    - Finish the end screen
*/

__attribute__((constructor)) void init(void)
{
    std::cout << "Snake loaded !\n";
}

extern "C"
{
    Arc::IGameModule *entryPoint(void)
    {
        return new Arc::Snake();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Snake unloaded !\n";
}

Arc::Snake::Snake()
{
    std::cout << "Snake is class constructed.\n";
}

Arc::Snake::~Snake()
{
    std::cout << "Snake is class destroyed.\n";
}

double Arc::Snake::getRandomPos(double min, double max)
{
    double randomValue = min + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX) / (max - min));
    double remainder = std::fmod(randomValue, 40.0);

    if (remainder != 0) {
        randomValue += 40.0 - remainder;
    }
    return randomValue;
}

bool Arc::Snake::appleIsOnSnake(Pos pos)
{
    Rect appleRect = calculateRect(pos, 30);
    Rect snakePartRect;

    for (const auto &part : this->gameData.player.tileSet) {
        snakePartRect = calculateRect(part.pos, 30);
        if (areaRectsInContact(appleRect, snakePartRect)) {
            return true;
        }
    }
    return false;
}

Arc::Pos Arc::Snake::computeNewSizeItem()
{
    Pos pos;

    pos.x = getRandomPos(0, 720) + 500;
    pos.y = getRandomPos(0, 680) + 100;
    while (appleIsOnSnake(pos)) {
        pos.x = getRandomPos(0, 720) + 500;
        pos.y = getRandomPos(0, 680) + 100;
    }
    return pos;
}

void Arc::Snake::stop()
{
    std::cout << "Snake is stopped.\n";
}

void Arc::Snake::isSnakeEatHimself()
{
    Rect snakeHeadRect;
    Rect snakePartRect;

    if (_actualScore < 5) {
        return;
    }
    snakeHeadRect = calculateRect(this->gameData.player.tileSet.at(0).pos, 30);
    for (std::size_t i = 0; i < this->gameData.player.tileSet.size(); ++i) {
        if (i != 0) {
            snakePartRect = calculateRect(this->gameData.player.tileSet.at(i).pos, 30);
            if (areaRectsInContact(snakeHeadRect, snakePartRect)) {
                initEndGame();
            }
        }
    }
}

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

bool Arc::Snake::areaRectsInContact(const Rect &rect1, const Rect &rect2)
{
    double rect1_right = rect1.x + rect1.w;
    double rect1_bottom = rect1.y + rect1.h;
    double rect2_right = rect2.x + rect2.w;
    double rect2_bottom = rect2.y + rect2.h;

    if (rect1.x > rect2_right || rect2.x > rect1_right || rect1.y > rect2_bottom || rect2.y > rect1_bottom) {
        return false;
    }
    return true;
}

Rect Arc::Snake::calculateRect(const Pos &pos, double size)
{
    Rect rect;

    rect.x = pos.x;
    rect.y = pos.y;
    rect.w = size;
    rect.h = size;
    return rect;
}

void Arc::Snake::snakeEatAFood()
{
    Pos tail;
    Rect snakeHeadRect = calculateRect(_snake.at(0), 39);
    Rect itemRect = calculateRect(this->gameData.item.at(0).pos, 39);

    if (areaRectsInContact(snakeHeadRect, itemRect)) {
        _actualScore += 1;
        this->gameData.textSet.at(1).text = "Actual score: " + std::to_string(_actualScore);
        this->gameData.item.at(0).pos = computeNewSizeItem();
        this->gameData.item.at(0).tile.pos = this->gameData.item.at(0).pos;
        tail = this->gameData.player.tileSet.back().pos;
        addElemBackSnake();
        createPlayer(tail, Arc::Size(40, 40), SNAKE_TAIL);
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
    isSnakeEatHimself();
    snakeEatAFood();
    return this->gameData;
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_snake";
        return name;
    }
}
