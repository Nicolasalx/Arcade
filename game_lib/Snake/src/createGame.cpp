/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** createGame
*/

#include "Snake.hpp"
#include "GameException.hpp"
#include "getFileContent.hpp"

/*
    ? Info of the snake
        - At the start the snake is the same sprite or the same character
            - The bonus is to pimp our snake and not have the same char for all the body

    - Find the image of the head, the body, and the end of the snake (So 3 images)
    - The elem in ncurses will be <=8~

    - At the start the snake has a size of 4 and he is at the middle of the map

    - Only handle key LEFT or key RIGHT
*/

void Arc::Snake::initHighScore()
{
    std::vector<std::string> tokensByLine = Arc::FileContent::getContent("./score/snakeScore.txt");

    if (tokensByLine.size() != 2) {
        throw Arc::GameException("Invalid file high score !");
    }
    _highScore = std::stoi(tokensByLine[1]);
}

void Arc::Snake::init()
{
    this->gameData.player.health = 100;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    initHighScore();
    createAllTexts();
    createMap();
    createSnake();
    createApple();

    _clockMove.setCooldown(std::chrono::milliseconds(100));
    _clockMove.start();
}

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

void Arc::Snake::createApple()
{
    Item item;

    item.pos = computeNewSizeItem();
    item.tile.imagePath = std::string(PATH_IMG) + "item.png";
    item.tile.color = Arc::Color::RED;
    item.tile.c = '@';
    item.tile.size = Arc::Size(40, 40);
    item.tile.pos = item.pos;
    this->gameData.item.push_back(item);
}

void Arc::Snake::createText(const std::string &name, Pos pos)
{
    Arc::Text text;

    text.text = name;
    text.color = Arc::Color::WHITE;
    text.fontPath = "fonts/DroidSansMono.ttf";
    text.pos = {pos.x, pos.y};
    text.size = 20;
    this->gameData.textSet.push_back(text);
}

void Arc::Snake::createAllTexts()
{
    createText("Username: " + this->gameData.player.userName, Arc::Pos(400, 50));
    createText("Actual score: " + std::to_string(_actualScore), Arc::Pos(700, 50));
    createText("High score: " + std::to_string(_highScore), Arc::Pos(1000, 50));
}

void Arc::Snake::createTile(Pos pos, Size sizeTile, TypeOfTile type)
{
    Arc::Tile tile;

    switch (type) {
        case MAP:
            tile.imagePath = std::string(PATH_IMG) + "bush.png";
            tile.color = Arc::Color::GREEN;
            tile.c = '#';
        break;
        case FLOOR:
            tile.imagePath = std::string(PATH_IMG) + "floor.png";
            tile.color = Arc::Color::GREEN;
            tile.c = ' ';
        break;
    }
    tile.size = sizeTile;
    tile.pos = pos;
    this->gameData.tileSet.push_back(tile);
}

void Arc::Snake::createPlayer(Pos pos, Size sizeTile, SnakeBody snakeBody)
{
    Tile tile;

    switch (snakeBody) {
        case SNAKE_HEAD:
            tile.imagePath = std::string(PATH_IMG) + "head.png";
            tile.c = '1';
            break;
        case SNAKE_BODY:
            tile.imagePath = std::string(PATH_IMG) + "body.png";
            tile.c = '=';
            break;
        case SNAKE_TAIL:
            tile.imagePath = std::string(PATH_IMG) + "tail.png";
            tile.c = '2';
            break;
    }
    tile.color = Arc::Color::CYAN;
    tile.size = sizeTile;
    tile.pos = pos;

    _snake.push_back(pos);
    this->gameData.player.tileSet.push_back(tile);
}

void Arc::Snake::createSnake()
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
