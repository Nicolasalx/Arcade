/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** createMap
*/

#include "Snake.hpp"

void Arc::Snake::putNewBoxInMap(TypeOfTile type, Pos pos)
{
    BoxMap box;

    box.type = type;
    box.pos = pos;
    createTile(Arc::Pos(pos.x, pos.y), Arc::Size(SIZE_BORDER, SIZE_BORDER), type);
}

void Arc::Snake::createNewBoxMap(std::size_t i, size_t j, double posX, double posY)
{
    if (i == 0 || j == 0 || j == SIZE_MAP - 1 || i == SIZE_MAP - 1) {
        putNewBoxInMap(MAP, Arc::Pos(posX, posY));
    } else {
        putNewBoxInMap(FLOOR, Arc::Pos(posX, posY));
    }
}

void Arc::Snake::createMap()
{
    double posX = X_POS_MAP;
    double posY = Y_POS_MAP;

    for (std::size_t i = 0; i < SIZE_MAP; ++i) {
        std::vector<BoxMap> tmpBox;
        for (std::size_t j = 0; j < SIZE_MAP; ++j) {
            createNewBoxMap(i, j, posX, posY);
            posX += SIZE_BORDER;
        }
        posX = X_POS_MAP;
        posY += SIZE_BORDER;
    }
}
