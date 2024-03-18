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
    }
    tile.size = sizeTile;
    tile.pos = pos;
    this->gameData.tileSet.push_back(tile);
}

void Arc::Snake::createPlayer(Pos pos, Size sizeTile, SnakeBody snakeBody)
{
    Tile tile;
    SnakeMove snakeMove;

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
    snakeMove.snakeBody = snakeBody;
    snakeMove.pos = pos;
    tile.color = Arc::Color::CYAN;
    tile.size = sizeTile;
    tile.pos = pos;
    _snakeMove.push_back(snakeMove);
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

void Arc::Snake::createApple()
{
    // Checker si la pomme n'est pas sur le serpent
    double randomX = getRandomPos(540, 1260);
    double randomY = getRandomPos(140, 820);
    createTile(Arc::Pos(randomX, randomY), Arc::Size(SIZE_BORDER, SIZE_BORDER), FOOD);
}

Arc::Pos Arc::Snake::findBoxPos(std::size_t idxSearch)
{
    Pos pos;

    for (std::size_t i = 0; i < idxSearch; ++i) {
        if (i % SIZE_MAP == 0) {
            pos.x += 1;
            pos.y = 0;
        } else {
            pos.y += 1;
        }
    }
    return pos;
}

void Arc::Snake::init()
{
    this->gameData.player.health = 100;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

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

    createSnake();
    createApple();

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

void Arc::Snake::moveSnakeUp()
{
    if (_snakeMove.at(0).nextDirection != DOWN) {
        _snakeMove.at(0).nextDirection = UP;
    }
}

void Arc::Snake::moveSnakeDown()
{
    if (_snakeMove.at(0).nextDirection != UP) {
        _snakeMove.at(0).nextDirection = DOWN;
    }
}

void Arc::Snake::moveSnakeLeft()
{
    if (_snakeMove.at(0).nextDirection != RIGHT) {
        _snakeMove.at(0).nextDirection = LEFT;
    }
}

void Arc::Snake::moveSnakeRight()
{
    if (_snakeMove.at(0).nextDirection != LEFT) {
        _snakeMove.at(0).nextDirection = RIGHT;
    }
}

void Arc::Snake::moveNextCase()
{
    /*
        for (all_part_of_snake) {
            if (nextDirection(i - 1) != nextDirection(i)) {
                if (posExpected )
            }
        }
    
    
    */

    for (std::size_t i = 0; i < _snakeMove.size(); ++i) {
        if (i != 0) {
            _snakeMove.at(i).nextDirection = _snakeMove.at(i - 1).nextDirection;
        }

        switch (_snakeMove.at(i).nextDirection) {
        case UP:
            _snakeMove.at(i).pos.y -= SIZE_MAP;
            break;
        case DOWN:
            _snakeMove.at(i).pos.y += SIZE_MAP;
            break;
        case LEFT:
            _snakeMove.at(i).pos.x -= SIZE_MAP;
            break;
        case RIGHT:
            _snakeMove.at(i).pos.x += SIZE_MAP;
            break;
        }
        this->gameData.player.tileSet[i].pos = _snakeMove[i].pos;
    }
}

void Arc::Snake::endTheGame()
{
    for (const auto _snakeBody : _snakeMove) {
        if (_snakeBody.pos.x <= 500 || _snakeBody.pos.x >= 1260 ||
            _snakeBody.pos.y <= 100 || _snakeBody.pos.y >= 860) {
                //this->gameData.textSet.clear();
                //this->gameData.tileSet.clear();
                //this->gameData.player.health = 0;
            }
    }
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

const Arc::GameData &Arc::Snake::update(const Arc::Event &event)
{
    for (const auto &evt : event.eventType) {
        switch (evt) {
            case Arc::EventType::UP:
                moveSnakeUp();
            break;
            case Arc::EventType::DOWN:
                moveSnakeDown();
            break;
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
    moveNextCase();
    //checkHighScore();
    //snakeEatAFood();
    //isSnakeFillingAllTheMap();
    endTheGame();
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
