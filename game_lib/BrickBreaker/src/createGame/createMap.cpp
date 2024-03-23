/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** createMap
*/

#include "BrickBreaker.hpp"
#include "getFileContent.hpp"

void Arc::BrickBreaker::createBrick(Pos pos)
{
    Tile tile;

    tile.imagePath = std::string(PATH_IMG) + "map/blueBox.png";
    tile.c = '@';
    tile.color = Arc::Color::CYAN;
    tile.size = Arc::Size(40, 40);
    tile.pos = pos;
    this->gameData.enemy.at(0).tileSet.push_back(tile);
}

void Arc::BrickBreaker::createWall(Pos pos)
{
    Tile tile;

    tile.imagePath = std::string(PATH_IMG) + "map/wall.png";
    tile.c = '#';
    tile.color = Arc::Color::CYAN;
    tile.size = Arc::Size(40, 40);
    tile.pos = pos;

    this->gameData.tileSet.push_back(tile);
}

void Arc::BrickBreaker::createPlayer(Pos pos)
{
    Tile tile;

    tile.imagePath = std::string(PATH_IMG) + "player/player.png";
    tile.c = '_';
    tile.color = Arc::Color::CYAN;
    tile.size = Arc::Size(120, 40);
    tile.pos = pos;
    this->gameData.player.tileSet.push_back(tile);
}

void Arc::BrickBreaker::createBall(Pos pos)
{
    Item item;
    Tile tile;

    tile.imagePath = std::string(PATH_IMG) + "ball/ball.png";
    tile.c = '0';
    tile.color = Arc::Color::CYAN;
    tile.size = Arc::Size(40, 40);
    tile.pos = pos;
    item.tile = tile;
    item.pos = pos;
    this->gameData.item.push_back(item);
}

void Arc::BrickBreaker::chooseElemCreate(char c, Pos pos)
{
    switch (c) {
        case '#':
            createWall(pos);
            break;
        case '@':
            createBrick(pos);
            break;
        case '0':
            createBall(pos);
            break;
        case '_':
            createPlayer(pos);
            break;
    }
}

void Arc::BrickBreaker::createMap()
{
    Pos posScreen;
    std::size_t numMap = 1; // ! On pourra changer de facon random
    std::size_t indexPlayer = 0;

    posScreen.x = X_POS_MAP;
    posScreen.y = Y_POS_MAP;
    _mapArray = Arc::FileContent::getArrayFromContent(std::string(PATH_IMG) + "map_" + std::to_string(numMap) + ".txt");
    for (std::size_t i = 0; i < BOX_WIDTH_MAP; ++i) {
        for (std::size_t j = 0; j < BOX_HEIGHT_MAP; ++j) {
            if (indexPlayer <= 0 || indexPlayer == 3) {
                chooseElemCreate(_mapArray.at(i).at(j), posScreen);
            }
            if (_mapArray.at(i).at(j) == '_') {
                ++indexPlayer;
            }
            posScreen.x += SIZE_BORDER;
        }
        posScreen.x = X_POS_MAP;
        posScreen.y += SIZE_BORDER;
    }
}
