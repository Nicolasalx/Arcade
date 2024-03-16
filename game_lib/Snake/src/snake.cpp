/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snake
*/

#include <iostream>
#include "Snake.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "Snake loaded !\n";
}

extern "C"
{
    Arc::IGameModule *entryPoint(void)
    {
        return new Arc::Snake();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Snake unloaded !\n";
}

Arc::Snake::Snake()
{
    std::cout << "Snake is class constructed.\n";
}

Arc::Snake::~Snake()
{
    std::cout << "Snake is class destroyed.\n";
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
        case FOOD:
            tile.imagePath = std::string(PATH_IMG) + "apple.png";
            tile.color = Arc::Color::RED;
            tile.c = '@';
        break;
        default:
            break;
    }
    tile.size = sizeTile;
    tile.pos = pos;
    this->gameData.tileSet.push_back(tile);
}

void Arc::Snake::createPlayer(Pos pos, Size sizeTile, char character)
{
    Tile tile;

    this->gameData.player.health = 100;
    tile.imagePath = std::string(PATH_IMG) + "snakehead.png";
    tile.color = Arc::Color::CYAN;
    tile.c = character;
    tile.size = sizeTile;
    tile.pos = pos;
    this->gameData.player.tileSet.push_back(tile);
}

double Arc::Snake::getRandomPos(double min, double max)
{
    return min + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX / (max - min)));
}

void Arc::Snake::putNewBoxInMap(TypeOfTile type, Pos pos, std::vector<BoxMap> &tmpBox)
{
    BoxMap box;

    box.type = type;
    box.pos = pos;
    createTile(Arc::Pos(pos.x, pos.y), Arc::Size(SIZE_BORDER, SIZE_BORDER), type);
    tmpBox.push_back(box);
}

Arc::Pos Arc::Snake::findBoxPos(std::size_t idxSearch)
{
    Pos pos;

    for (std::size_t i = 0; i < idxSearch; ++i) {
        if (i == SIZE_MAP) {
            pos.x += 1;
            pos.y -= SIZE_MAP;
        } else {
            pos.y += 1;
        }
    }
    return pos;
}

void Arc::Snake::init()
{
    // TODO Create the 3 texts
    createText("Username: " + this->gameData.player.userName, Arc::Pos(400, 50));
    createText("Actual score: " + std::to_string(_actualScore), Arc::Pos(700, 50));
    createText("High score: " + std::to_string(_highScore), Arc::Pos(1000, 50));

    // TODO Create the map (10 x 10)
    double posX = X_POS_MAP;
    double posY = Y_POS_MAP;

    for (int i = 0; i < SIZE_MAP; ++i) {
        std::vector<BoxMap> tmpBox;
        for (int j = 0; j < SIZE_MAP; ++j) {
            if (i == 0 || j == 0 || j == SIZE_MAP - 1 || i == SIZE_MAP - 1) {
                putNewBoxInMap(MAP, Arc::Pos(posX, posY), tmpBox);
            } else {
                putNewBoxInMap(FLOOR, Arc::Pos(posX, posY), tmpBox);
            }
            posX += SIZE_BORDER;
        }
        _map.push_back(tmpBox);
        posX = X_POS_MAP;
        posY += SIZE_BORDER;
    }

    //std::size_t middleMap = ((SIZE_MAP - 2) * 10) + (SIZE_MAP / 2) - 2;
//
    //for (std::size_t i = 0; i < 4; ++i) {
    //    this->gameData.tileSet[middleMap + i].imagePath = std::string(PATH_IMG) + "snakehead.png";
    //    Pos pos = findBoxPos(middleMap + i);
    //    _map[pos.x][pos.y].type = SNAKE;
    //}


    // find the 4 char at the middle



    //this->gameData.tileSet[10] = tile;
    // this->gameData.player.tileSet represent the number of tileset -> Use this for Snake

    // Implement the snake

    //createTile(Arc::Pos(randomizeSizeX, randomizeSizeY), (Arc::Size) {40, 40}, FOOD);

    /*
        ? Info of the snake
            - At the start the snake is the same sprite or the same character
                - The bonus is to pimp our snake and not have the same char for all the body

            - Find the image of the head, the body, and the end of the snake (So 3 images)
            - The elem in ncurses will be <=8~

            - At the start the snake has a size of 4 and he is at the middle of the map

            - Only handle key LEFT or key RIGHT
    */
}

void Arc::Snake::stop()
{
    std::cout << "Snake is stopped.\n";
}

void Arc::Snake::moveSnakeLeft()
{
    // move to left
}

void Arc::Snake::moveSnakeRight()
{
    // move of right
}

void Arc::Snake::endTheGame()
{
    // Check if the snake has hit his body || the snake has hit a border
    this->gameData.textSet.clear();
    this->gameData.tileSet.clear();
    this->gameData.player.health = 0;
}

void Arc::Snake::displayScreenEnd()
{
    if (this->gameData.player.health == 0) {
        // - You are dead
        // - Username / Actual Score / High Score
        // - Press Q to Go back Menu
    }
}

void Arc::Snake::checkHighScore()
{
    // If the actual score > high score ----->>>> write on the file the new high score with the username
}

void Arc::Snake::snakeEatAFood()
{
    // If the snake has eat a food
    _actualScore += 1;
    // Insert at the size - 1 un élément (Pour préserver la queue)
    // Il faut insérer un tile
    // L'emplacement de la pomme doit etre regénérer
}

void Arc::Snake::isSnakeFillingAllTheMap()
{
    // Check if the snake fill al the map
}

void Arc::Snake::moveNextCase()
{
    // Move next case
}

const Arc::GameData &Arc::Snake::update(const Arc::Event &event)
{
    for (const auto &evt : event.eventType) {
        switch (evt) {
            case Arc::EventType::LEFT:
                moveSnakeLeft();
            break;
            case Arc::EventType::RIGHT:
                moveSnakeRight();
            break;
            default:
            break;
        }
    }
    //moveNextCase();
    //checkHighScore();
    //snakeEatAFood();
    //isSnakeFillingAllTheMap();
    //endTheGame();
    //displayScreenEnd();
    return this->gameData;
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_snake";
        return name;
    }
}
