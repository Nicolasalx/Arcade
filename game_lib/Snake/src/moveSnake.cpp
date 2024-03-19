/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** moveSnake
*/

#include "Snake.hpp"


void Arc::Snake::changeDirection(NextDirection nextDir)
{
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
}

void Arc::Snake::moveNextCase()
{
    Pos new_head;

    if (!_clockMove.isElapsed()) {
        return;
    }
    _clockMove.reset();
    new_head = _snake[0];
    switch (_direction) {
        case UP:
            new_head.y -= SIZE_BORDER;
            break;
        case DOWN:
            new_head.y += SIZE_BORDER;
            break;
        case LEFT:
            new_head.x -= SIZE_BORDER;
            break;
        case RIGHT:
            new_head.x += SIZE_BORDER;
            break;
    }
    _snake.insert(_snake.begin(), new_head);
    _snake.pop_back();
    for (std::size_t i = 0; i < _snake.size(); ++i) {
        this->gameData.player.tileSet[i].pos = _snake[i];
    }
}

void Arc::Snake::addElemBackSnake()
{
    this->gameData.player.tileSet.back().imagePath = std::string(PATH_IMG) + "body.png";
    this->gameData.player.tileSet.back().c = '=';
}
