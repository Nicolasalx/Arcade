/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** moveSnake
*/

#include "Nibbler.hpp"

void Arc::Nibbler::changeDirection(NextDirection nextDir)
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

void Arc::Nibbler::moveNextCase()
{
    SnakeMove snakeMove;

    if (!_clockMove.isElapsed()) {
        return;
    }
    _clockMove.reset();
    snakeMove = _snake[0];
    switch (_direction) {
        case UP:
            if (_mapArray.at(_headSnake.x - 1).at(_headSnake.y) != '#') {
                snakeMove.pos.y -= SIZE_BORDER;
                snakeMove.nextDirection = UP;
                _headSnake.x -= 1;
                _hasMoved = true;
            }
            break;
        case DOWN:
            if (_mapArray.at(_headSnake.x + 1).at(_headSnake.y) != '#') {
                snakeMove.pos.y += SIZE_BORDER;
                snakeMove.nextDirection = DOWN;
                _headSnake.x += 1;
                _hasMoved = true;
            }
            break;
        case LEFT:
            if (_mapArray.at(_headSnake.x).at(_headSnake.y - 1) != '#') {
                snakeMove.pos.x -= SIZE_BORDER;
                snakeMove.nextDirection = LEFT;
                _headSnake.y -= 1;
                _hasMoved = true;
            }
            break;
        case RIGHT:
            if (_mapArray.at(_headSnake.x).at(_headSnake.y + 1) != '#') {
                snakeMove.pos.x += SIZE_BORDER;
                snakeMove.nextDirection = RIGHT;
                _headSnake.y += 1;
                _hasMoved = true;
            }
            break;
    }
    _mapArray.at(_headSnake.x).at(_headSnake.y) = 'S';

    //for (std::size_t i = 0; i < SIZE_MAP; ++i) {
    //    for (std::size_t j = 0; j < SIZE_MAP; ++j) {
    //        std::cout << _mapArray.at(i).at(j);
    //    }
    //    std::cout << "\n";
    //}

    if (_hasMoved == false) {
        return;
    }
    _snake.insert(_snake.begin(), snakeMove);
    _snake.pop_back();
    for (std::size_t i = 0; i < _snake.size(); ++i) {
        this->gameData.player.tileSet[i].pos = _snake[i].pos;
    }
    _hasMoved = false;
}

void Arc::Nibbler::addElemBackSnake()
{
    this->gameData.player.tileSet.back().imagePath = std::string(PATH_IMG) + "/body/horizontal.png";
    this->gameData.player.tileSet.back().c = '=';
}
