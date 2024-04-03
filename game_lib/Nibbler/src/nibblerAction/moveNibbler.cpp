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

void Arc::Nibbler::mooveUp(SnakeMoove &snakeMoove)
{
    snakeMoove.pos.y -= SIZE_BORDER;
    snakeMoove.nextDirection = UP;
    _headSnake.x -= 1;
    _hasMoved = true;
}

void Arc::Nibbler::mooveDown(SnakeMoove &snakeMoove)
{
    snakeMoove.pos.y += SIZE_BORDER;
    snakeMoove.nextDirection = DOWN;
    _headSnake.x += 1;
    _hasMoved = true;
}

void Arc::Nibbler::mooveLeft(SnakeMoove &snakeMoove)
{
    snakeMoove.pos.x -= SIZE_BORDER;
    snakeMoove.nextDirection = LEFT;
    _headSnake.y -= 1;
    _hasMoved = true;
}

void Arc::Nibbler::mooveRight(SnakeMoove &snakeMoove)
{
    snakeMoove.pos.x += SIZE_BORDER;
    snakeMoove.nextDirection = RIGHT;
    _headSnake.y += 1;
    _hasMoved = true;
}

void Arc::Nibbler::automaticMooveVertical(SnakeMoove &snakeMoove)
{
    if (_mapArray.at(_headSnake.x).at(_headSnake.y - 1) != '#' && _mapArray.at(_headSnake.x).at(_headSnake.y + 1) == '#') {
        mooveLeft(snakeMoove);
        _direction = LEFT;
    } else if (_mapArray.at(_headSnake.x).at(_headSnake.y - 1) == '#' && _mapArray.at(_headSnake.x).at(_headSnake.y + 1) != '#') {
        mooveRight(snakeMoove);
        _direction = RIGHT;
    }
}

void Arc::Nibbler::automaticMooveHorizontal(SnakeMoove &snakeMoove)
{
    if (_mapArray.at(_headSnake.x - 1).at(_headSnake.y) != '#' && _mapArray.at(_headSnake.x + 1).at(_headSnake.y) == '#') {
        mooveUp(snakeMoove);
        _direction = UP;
    } else if (_mapArray.at(_headSnake.x - 1).at(_headSnake.y) == '#' && _mapArray.at(_headSnake.x + 1).at(_headSnake.y) != '#') {
        mooveDown(snakeMoove);
        _direction = DOWN;
    }
}

void Arc::Nibbler::switchDirection(SnakeMoove &snakeMoove)
{
    switch (_direction) {
        case UP:
            if (_mapArray.at(_headSnake.x - 1).at(_headSnake.y) != '#') {
                mooveUp(snakeMoove);
            } else {
                automaticMooveVertical(snakeMoove);
            }
            break;
        case DOWN:
            if (_mapArray.at(_headSnake.x + 1).at(_headSnake.y) != '#') {
                mooveDown(snakeMoove);
            } else {
                automaticMooveVertical(snakeMoove);
            }
            break;
        case LEFT:
            if (_mapArray.at(_headSnake.x).at(_headSnake.y - 1) != '#') {
                mooveLeft(snakeMoove);
            } else {
                automaticMooveHorizontal(snakeMoove);
            }
            break;
        case RIGHT:
            if (_mapArray.at(_headSnake.x).at(_headSnake.y + 1) != '#') {
                mooveRight(snakeMoove);
            } else {
                automaticMooveHorizontal(snakeMoove);
            }
            break;
    }
}

void Arc::Nibbler::moveNextCase()
{
    SnakeMoove snakeMoove;

    if (!_clockMove.isElapsed()) {
        return;
    }
    _clockMove.reset();
    snakeMoove = _snake[0];
    switchDirection(snakeMoove);
    _mapArray.at(_headSnake.x).at(_headSnake.y) = 'S';
    if (!_hasMoved) {
        return;
    }
    _snake.insert(_snake.begin(), snakeMoove);
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
