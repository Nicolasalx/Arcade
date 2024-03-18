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
    }
    tile.size = sizeTile;
    tile.pos = pos;
    this->gameData.tileSet.push_back(tile);
}

void Arc::Snake::changePartSnake()
{
    this->gameData.player.tileSet.back().imagePath = std::string(PATH_IMG) + "body.png";
    this->gameData.player.tileSet.back().c = '=';
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
        _listDirection.push_front(RIGHT);
    }
}

Arc::Pos Arc::Snake::computeNewSizeItem()
{
    Pos pos;

    pos.x = getRandomPos(540, 1260);
    pos.y = getRandomPos(140, 820);
    return pos;
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
    //this->gameData.tileSet.push_back(item.tile);
}

void Arc::Snake::createAllTexts()
{
    createText("Username: " + this->gameData.player.userName, Arc::Pos(400, 50));
    createText("Actual score: " + std::to_string(_actualScore), Arc::Pos(700, 50));
    createText("High score: " + std::to_string(_highScore), Arc::Pos(1000, 50));
}

void Arc::Snake::createMap()
{
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
}

void Arc::Snake::init()
{
    this->gameData.player.health = 100;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    createAllTexts();
    createMap();
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

    _clockMove.setCooldown(std::chrono::milliseconds(100));
    _clockMove.start();
}

void Arc::Snake::stop()
{
    std::cout << "Snake is stopped.\n";
}

void Arc::Snake::changeDirection(NextDirection nextDir)
{
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
}

void Arc::Snake::moveNextCase()
{
    Pos new_head;

    if (!_clockMove.isElapsed()) {
        return;
    }
    _clockMove.reset();
    new_head = _snake[0];
    switch (_direction) {
        case UP:
            new_head.y -= SIZE_BORDER;
            break;
        case DOWN:
            new_head.y += SIZE_BORDER;
            break;
        case LEFT:
            new_head.x -= SIZE_BORDER;
            break;
        case RIGHT:
            new_head.x += SIZE_BORDER;
            break;
    }
    _snake.insert(_snake.begin(), new_head);
    _snake.pop_back();
    for (std::size_t i = 0; i < _snake.size(); ++i) {
        this->gameData.player.tileSet[i].pos = _snake[i];
    }
}

void Arc::Snake::initEndGame()
{
    this->gameData.textSet.clear();
    this->gameData.tileSet.clear();
    this->gameData.player.tileSet.clear();
    // Clear les item
    this->gameData.player.health = 0;
    _isEnd = true;

    createText("You loose !" + this->gameData.player.userName, Arc::Pos(400, 50));
    createText("You score: " + std::to_string(_actualScore), Arc::Pos(600, 50));
    createText("The highscore is: " + std::to_string(_highScore), Arc::Pos(800, 50));
}

void Arc::Snake::endTheGame()
{
    if (_isEnd == true) {
        return;
    }
    for (const auto part : _snake) {
        if (part.x <= 500 || part.x >= 1260 ||
            part.y <= 100 || part.y >= 860) {
                initEndGame();
        }
    }
}

void Arc::Snake::checkHighScore()
{
    // If the actual score > high score ----->>>> write on the file the new high score with the username
}

bool Arc::Snake::areaRectsInContact(const Rect &rect1, const Rect &rect2)
{
    double rect1_right = rect1.x + rect1.w;
    double rect1_bottom = rect1.y + rect1.h;
    double rect2_right = rect2.x + rect2.w;
    double rect2_bottom = rect2.y + rect2.h;

    if (rect1.x > rect2_right || rect2.x > rect1_right || rect1.y > rect2_bottom || rect2.y > rect1_bottom) {
        return false;
    }
    return true;
}

Rect Arc::Snake::calculateRect(const Pos &pos, double size)
{
    Rect rect;

    rect.x = pos.x;
    rect.y = pos.y;
    rect.w = size;
    rect.h = size;
    return rect;
}

void Arc::Snake::snakeEatAFood()
{
    Pos tail;
    Rect snakeHeadRect = calculateRect(_snake.at(0), 40);
    Rect itemRect = calculateRect(this->gameData.item.at(0).pos, 40);

    if (areaRectsInContact(snakeHeadRect, itemRect)) {
        _actualScore += 1;
        this->gameData.textSet.at(1).text = "Actual score: " + std::to_string(_actualScore);
        this->gameData.item.at(0).pos = computeNewSizeItem();
        this->gameData.item.at(0).tile.pos = this->gameData.item.at(0).pos;
        tail = this->gameData.player.tileSet.back().pos;

        changePartSnake();
        createPlayer(tail, Arc::Size(40, 40), SNAKE_TAIL);
    }
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
                changeDirection(UP);
            break;
            case Arc::EventType::DOWN:
                changeDirection(DOWN);
            break;
            case Arc::EventType::LEFT:
                changeDirection(LEFT);
            break;
            case Arc::EventType::RIGHT:
                changeDirection(RIGHT);
            break;
            default:
            break;
        }
    }
    moveNextCase();
    //checkHighScore();
    snakeEatAFood();
    //isSnakeFillingAllTheMap();
    endTheGame();
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
