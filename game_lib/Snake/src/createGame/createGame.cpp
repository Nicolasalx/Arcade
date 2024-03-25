/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** createGame
*/

#include "Snake.hpp"

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

void Arc::Snake::createText(const std::string &name, Pos pos, Color color)
{
    Arc::Text text;

    text.text = name;
    text.color = color;
    text.fontPath = "fonts/DroidSansMono.ttf";
    text.pos = {pos.x, pos.y};
    text.size = 20;
    this->gameData.textSet.push_back(text);
}

void Arc::Snake::createAllTexts()
{
    createText("Username:\n" + this->gameData.player.userName, Arc::Pos(500, 40), Arc::Color::WHITE);
    createText("Actual score: " + std::to_string(_actualScore), Arc::Pos(800, 50), Arc::Color::WHITE);
    createText("High score: " + std::to_string(_highScore), Arc::Pos(1100, 50), Arc::Color::WHITE);
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
