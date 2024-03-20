/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** initAll
*/

#include "Snake.hpp"
#include "GameException.hpp"
#include "getFileContent.hpp"

/*
    ? Info of the snake
        - At the start the snake is the same sprite or the same character
            - The bonus is to pimp our snake and not have the same char for all the body

    - Find the image of the head, the body, and the end of the snake (So 3 images)
    - The elem in ncurses will be <=8~

    - At the start the snake has a size of 4 and he is at the middle of the map

    - Only handle key LEFT or key RIGHT
*/

void Arc::Snake::initHighScore()
{
    std::vector<std::string> tokensByLine = Arc::FileContent::getContent("./score/snakeScore.txt");

    if (tokensByLine.size() != 2) {
        throw Arc::GameException("Invalid file high score !");
    }
    _highScore = std::stoi(tokensByLine[1]);
}

void Arc::Snake::init()
{
    this->gameData.player.health = 100;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    initHighScore();
    createAllTexts();
    createMap();
    createSnake();
    createApple();

    _clockMove.setCooldown(std::chrono::milliseconds(100));
    _clockMove.start();
}
