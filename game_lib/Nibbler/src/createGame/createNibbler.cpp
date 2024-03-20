/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** createSnake
*/

#include "Nibbler.hpp"

void Arc::Nibbler::createPlayer(Pos pos, Size sizeTile, SnakeBody snakeBody)
{
    Tile tile;
    SnakeMove snakeMove;

    switch (snakeBody) {
        case SNAKE_HEAD:
            tile.imagePath = std::string(PATH_IMG) + "body/headLeft.png";
            tile.c = '1';
            break;
        case SNAKE_BODY:
            tile.imagePath = std::string(PATH_IMG) + "body/horizontal.png";
            tile.c = '=';
            break;
        case SNAKE_TAIL:
            tile.imagePath = std::string(PATH_IMG) + "item.png";
            tile.c = '2';
            break;
    }
    tile.color = Arc::Color::CYAN;
    tile.size = sizeTile;
    tile.pos = pos;
    snakeMove.pos = pos;
    snakeMove.nextDirection = LEFT;

    _snake.push_back(snakeMove);
    this->gameData.player.tileSet.push_back(tile);
}

void Arc::Nibbler::createSnake()
{
    std::size_t middleMap = ((SIZE_MAP - 2) * 10) + (SIZE_MAP / 2) - 2;

    for (std::size_t i = 0; i < 4; ++i) {
        if (i == 0) {
            createPlayer(this->gameData.tileSet[middleMap + i].pos, Arc::Size(40, 40), SNAKE_HEAD);
        } else if (i == 3) {
           createPlayer(this->gameData.tileSet[middleMap + i].pos, Arc::Size(40, 40), SNAKE_TAIL);
        } else {
            createPlayer(this->gameData.tileSet[middleMap + i].pos, Arc::Size(40, 40), SNAKE_BODY);
        }
    }
}
