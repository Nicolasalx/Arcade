/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** moveSnake
*/

#include "Snake.hpp"

void Arc::Snake::changeDirection(NextDirection nextDir)
{
    if (!_clockEvent.isElapsed()) {
        return;
    }
    _clockEvent.reset();

    if (nextDir == UP && _direction != DOWN) {
        _direction = nextDir;
    }
    if (nextDir == DOWN && _direction != UP) {
        _direction = nextDir;
    }
    if (nextDir == RIGHT && _direction != LEFT) {
        _direction = nextDir;
    }
    if (nextDir == LEFT && _direction != RIGHT) {
        _direction = nextDir;
    }
    _hasInitDir = true;
}

void Arc::Snake::moveNextCase()
{
    SnakeMove snakeMove;

    if (!_clockMove.isElapsed()) {
        return;
    }
    _clockMove.reset();
    snakeMove = _snake[0];
    switch (_direction) {
        case UP:
            snakeMove.pos.y -= SIZE_BORDER;
            snakeMove.nextDirection = UP;
            break;
        case DOWN:
            snakeMove.pos.y += SIZE_BORDER;
            snakeMove.nextDirection = DOWN;
            break;
        case LEFT:
            snakeMove.pos.x -= SIZE_BORDER;
            snakeMove.nextDirection = LEFT;
            break;
        case RIGHT:
            snakeMove.pos.x += SIZE_BORDER;
            snakeMove.nextDirection = RIGHT;
            break;
    }
    _snake.insert(_snake.begin(), snakeMove);
    _snake.pop_back();
    for (std::size_t i = 0; i < _snake.size(); ++i) {
        this->gameData.player.tileSet[i].pos = _snake[i].pos;
    }
}

void Arc::Snake::addElemBackSnake()
{
    this->gameData.player.tileSet.back().imagePath = std::string(PATH_IMG) + "/body/horizontal.png";
    this->gameData.player.tileSet.back().c = '=';
}
