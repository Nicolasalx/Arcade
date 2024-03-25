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

void Arc::Snake::switchDirection(SnakeMoove &snakeMoove)
{
    switch (_direction) {
        case UP:
            snakeMoove.pos.y -= SIZE_BORDER;
            snakeMoove.nextDirection = UP;
            break;
        case DOWN:
            snakeMoove.pos.y += SIZE_BORDER;
            snakeMoove.nextDirection = DOWN;
            break;
        case LEFT:
            snakeMoove.pos.x -= SIZE_BORDER;
            snakeMoove.nextDirection = LEFT;
            break;
        case RIGHT:
            snakeMoove.pos.x += SIZE_BORDER;
            snakeMoove.nextDirection = RIGHT;
            break;
    }
}

void Arc::Snake::moveNextCase()
{
    SnakeMoove snakeMoove;

    if (!_clockMove.isElapsed()) {
        return;
    }
    _clockMove.reset();
    snakeMoove = _snake[0];
    switchDirection(snakeMoove);
    _snake.insert(_snake.begin(), snakeMoove);
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
