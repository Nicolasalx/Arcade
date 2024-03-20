/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** createMap
*/

#include "Nibbler.hpp"
#include "getFileContent.hpp"

void Arc::Nibbler::putNewBoxInMap(TypeOfTile type, Pos pos)
{
    BoxMap box;

    box.type = type;
    box.pos = pos;
    createTile(Arc::Pos(pos.x, pos.y), Arc::Size(SIZE_BORDER, SIZE_BORDER), type);
}

void Arc::Nibbler::createNewBoxMap(TypeOfTile type, double posX, double posY)
{
    if (type == WALL) {
        putNewBoxInMap(WALL, Arc::Pos(posX, posY));
    } else {
        putNewBoxInMap(FLOOR, Arc::Pos(posX, posY));
    }
}

int Arc::Nibbler::getRandomPosToInt(int min, int max)
{
    return min + (std::rand()) / ((RAND_MAX) / (max - min));
}

void Arc::Nibbler::createMap()
{
    double posX = X_POS_MAP;
    double posY = Y_POS_MAP;
    int numMap = 0;

    numMap = getRandomPosToInt(1, 3);
    _mapArray = Arc::FileContent::getArrayFromContent("./game_src/nibbler/map_" + std::to_string(numMap) + ".txt");

    for (std::size_t i = 0; i < SIZE_MAP; ++i) {
        for (std::size_t j = 0; j < SIZE_MAP; ++j) {
            if (_mapArray.at(i).at(j) == '#') {
                createNewBoxMap(WALL, posX, posY);
            } else {
                createNewBoxMap(FLOOR, posX, posY);
            }
            posX += SIZE_BORDER;
        }
        posX = X_POS_MAP;
        posY += SIZE_BORDER;
    }
}
