/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** createText
*/

#include "BrickBreaker.hpp"

void Arc::BrickBreaker::createText(const std::string &name, Pos pos, Color color)
{
    Arc::Text text;

    text.text = name;
    text.color = color;
    text.fontPath = "fonts/DroidSansMono.ttf";
    text.pos = {pos.x, pos.y};
    text.size = 20;
    this->gameData.textSet.push_back(text);
}

void Arc::BrickBreaker::createAllTexts()
{
    
}