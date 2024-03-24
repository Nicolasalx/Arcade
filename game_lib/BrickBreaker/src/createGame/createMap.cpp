/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** createMap
*/

#include "BrickBreaker.hpp"
#include "getFileContent.hpp"

void Arc::BrickBreaker::createBrickBlue(Tile &tile)
{
    tile.imagePath = std::string(PATH_IMG) + "map/blueBox.png";
    tile.c = '@';
    tile.color = Arc::Color::BLUE;
}

void Arc::BrickBreaker::createBrickColorGreen(Tile &tile)
{
    tile.imagePath = std::string(PATH_IMG) + "map/greenBox.png";
    tile.c = '@';
    tile.color = Arc::Color::GREEN;
}

void Arc::BrickBreaker::createBrickColorPurple(Tile &tile)
{
    tile.imagePath = std::string(PATH_IMG) + "map/purpleBox.png";
    tile.c = '@';
    tile.color = Arc::Color::MAGENTA;
}

void Arc::BrickBreaker::createBrickColorRed(Tile &tile)
{
    tile.imagePath = std::string(PATH_IMG) + "map/redBox.png";
    tile.c = '@';
    tile.color = Arc::Color::RED;
}

void Arc::BrickBreaker::createBrickColorYellow(Tile &tile)
{
    tile.imagePath = std::string(PATH_IMG) + "map/yellowBox.png";
    tile.c = '@';
    tile.color = Arc::Color::YELLOW;
}

void Arc::BrickBreaker::createBrick(ColorBrick color)
{
    Tile tile;

    switch (color) {
        case BLUE:
            createBrickBlue(tile); break;
        case GREEN:
            createBrickColorGreen(tile); break;
        case PURPLE:
            createBrickColorPurple(tile); break;
        case RED:
            createBrickColorRed(tile); break;
        case YELLOW:
            createBrickColorYellow(tile); break;
    }
    tile.size = Arc::Size(40, 40);
    tile.pos = _posScreen;
    this->gameData.enemy.at(0).tileSet.push_back(tile);
}

void Arc::BrickBreaker::createWall()
{
    Tile tile;

    tile.imagePath = std::string(PATH_IMG) + "map/wall.png";
    tile.c = '#';
    tile.color = Arc::Color::WHITE;
    tile.size = Arc::Size(40, 40);
    tile.pos = _posScreen;

    this->gameData.tileSet.push_back(tile);
}

void Arc::BrickBreaker::createPlayer()
{
    Tile tile;

    tile.imagePath = std::string(PATH_IMG) + "player/player.png";
    tile.c = '_';
    tile.color = Arc::Color::CYAN;
    tile.size = Arc::Size(120, 40);
    tile.pos = _posScreen;
    this->gameData.player.tileSet.push_back(tile);
}

void Arc::BrickBreaker::createBall()
{
    Item item;
    Tile tile;

    tile.imagePath = std::string(PATH_IMG) + "ball/ball.png";
    tile.c = '0';
    tile.color = Arc::Color::CYAN;
    tile.size = Arc::Size(40, 40);
    tile.pos = _posScreen;
    item.tile = tile;
    item.pos = _posScreen;
    _iniPosBall = _posScreen;
    this->gameData.item.push_back(item);
}

void Arc::BrickBreaker::chooseElemCreate(char c)
{
    switch (c) {
        case '#':
            createWall(); break;
        case 'B':
            createBrick(BLUE); break;
        case 'G':
            createBrick(GREEN); break;
        case 'P':
            createBrick(PURPLE); break;
        case 'R':
            createBrick(RED); break;
        case 'Y':
            createBrick(YELLOW); break;
        case '0':
            createBall(); break;
        case '_':
            createPlayer(); break;
    }
}

void Arc::BrickBreaker::createEachElemMap(std::size_t &indexPlayer, std::size_t i, std::size_t j)
{
    if (indexPlayer <= 0 || indexPlayer == 3) {
        chooseElemCreate(_mapArray.at(i).at(j));
    }
    if (_mapArray.at(i).at(j) == '_') {
        ++indexPlayer;
    }
}

void Arc::BrickBreaker::createMap()
{
    std::size_t numMap = 0;
    std::size_t indexPlayer = 0;

    _posScreen.x = X_POS_MAP;
    _posScreen.y = Y_POS_MAP;
    numMap = getRandomPosToInt(1, 4);
    _mapArray = Arc::FileContent::getArrayFromContent("./game_src/brickBreaker/map_" + std::to_string(numMap) + ".txt");
    for (std::size_t i = 0; i < BOX_WIDTH_MAP; ++i) {
        for (std::size_t j = 0; j < BOX_HEIGHT_MAP; ++j) {
            createEachElemMap(indexPlayer, i, j);
            _posScreen.x += SIZE_BORDER;
        }
        _posScreen.x = X_POS_MAP;
        _posScreen.y += SIZE_BORDER;
    }
}
