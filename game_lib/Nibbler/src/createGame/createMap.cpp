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
    box.posScreen = pos;
    createTile(Arc::Pos(pos.x, pos.y), Arc::Size(SIZE_BORDER, SIZE_BORDER), type);
}

void Arc::Nibbler::createNewBoxMap(TypeOfTile type, Pos posScreen)
{
    if (type == SNAKE) {
        if (this->gameData.player.tileSet.size() == 0) {
            createPlayer(posScreen, Arc::Size(40, 40), SNAKE_HEAD);
            putNewBoxInMap(SNAKE, Arc::Pos(posScreen.x, posScreen.y));
            _headSnake = Arc::Pos(18, 8);
            _mapArray.at(_headSnake.x).at(_headSnake.y) = 'S';
        } else if (this->gameData.player.tileSet.size() == 3) {
            createPlayer(posScreen, Arc::Size(40, 40), SNAKE_TAIL);
        } else {
            createPlayer(posScreen, Arc::Size(40, 40), SNAKE_BODY);
        }
    } else {
        putNewBoxInMap(type, Arc::Pos(posScreen.x, posScreen.y));
    }
}

int Arc::Nibbler::getRandomPosToInt(int min, int max)
{
    return min + (std::rand()) / ((RAND_MAX) / (max - min));
}

void Arc::Nibbler::createMap()
{
    Pos posScreen;
    int numMap = 0;

    posScreen.x = X_POS_MAP;
    posScreen.y = Y_POS_MAP;
    numMap = getRandomPosToInt(1, 3);
    _mapArray = Arc::FileContent::getArrayFromContent("./game_src/nibbler/map_" + std::to_string(numMap) + ".txt");

    for (std::size_t i = 0; i < SIZE_MAP; ++i) {
        for (std::size_t j = 0; j < SIZE_MAP; ++j) {
            if (i == 18 && (j == 8 || j == 9 || j == 10 || j == 11)) {
                createNewBoxMap(SNAKE, posScreen);
            } else if (_mapArray.at(i).at(j) == '#') {
                createNewBoxMap(WALL, posScreen);
            } else {
                createNewBoxMap(FLOOR, posScreen);
            }
            posScreen.x += SIZE_BORDER;
        }
        posScreen.x = X_POS_MAP;
        posScreen.y += SIZE_BORDER;
    }
}
