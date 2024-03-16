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

void Arc::Snake::createTile(Pos pos, std::size_t sizeTile,
    typeOfTile typeOfTile, char character)
{
    Arc::Tile tile;

    switch (typeOfTile) {
        case SNAKE:
            tile.imagePath = std::string(PATH_IMG) + "snakehead.png";
            tile.color = Arc::Color::CYAN;
            tile.c = character;
            tile.size = sizeTile;
            pos = pos;
            _snake.push_back(tile);
        break;
        case MAP:
            tile.imagePath = std::string(PATH_IMG) + "bush.png";
            tile.color = Arc::Color::GREEN;
            tile.c = character;
            tile.size = sizeTile;
            pos = pos;
            _map.push_back(tile);
        break;
        case FOOD:
            tile.imagePath = std::string(PATH_IMG) + "apple.png";
            tile.color = Arc::Color::RED;
            tile.c = character;
            tile.size = sizeTile;
            pos = pos;
            _food = tile;
        break;
        default:
            break;
    }
    this->gameData.tileSet.push_back(tile);
}

int getRandomPos(int min, int max)
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    return min + (std::rand() % (max - min + 1));
}

void Arc::Snake::init()
{
    this->gameData.player.health = 100;

    // TODO Create the 3 texts
    createText("Username: " + this->gameData.player.userName, (Arc::Pos) {300, 200});
    createText("Actual score: " + _actualScore, (Arc::Pos) {450, 200});
    createText("High score: " + _highScore, (Arc::Pos) {600, 200});

    // TODO Create the map (10 x 10)
    createTile((Arc::Pos) {100, 150}, 100, MAP, '#');
    createTile((Arc::Pos) {100, 200}, 100, MAP, '#');
    createTile((Arc::Pos) {100, 250}, 100, MAP, '#');
    createTile((Arc::Pos) {100, 300}, 100, MAP, '#');
    createTile((Arc::Pos) {100, 350}, 100, MAP, '#');
    createTile((Arc::Pos) {100, 400}, 100, MAP, '#');

    // TODO: Create the Snake (4)
    createTile((Arc::Pos) {500, 800}, 100, SNAKE, '~');
    createTile((Arc::Pos) {400, 800}, 100, SNAKE, '8');
    createTile((Arc::Pos) {300, 800}, 100, SNAKE, '=');
    createTile((Arc::Pos) {200, 800}, 100, SNAKE, '>');

    // Randomize the position of the food
    int randomizeSizeX = getRandomPos(200, 500); // The pos min and max need to be changed with the map values
    int randomizeSizeY = getRandomPos(300, 600); // The pos min and max need to be changed with the map values

    createTile((Arc::Pos) {randomizeSizeX, randomizeSizeY}, 100, FOOD, '@');

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

    // move of one case

    // Check if the snake has eaten the food
}

void Arc::Snake::moveSnakeRight()
{
    // move of right
    // move of one case

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
    checkHighScore();
    snakeEatAFood();
    isSnakeFillingAllTheMap();
    endTheGame();
    displayScreenEnd();
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
