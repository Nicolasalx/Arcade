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
    createText("Username: " + this->gameData.player.userName, Arc::Pos(100, 100), Arc::Color::WHITE);
    createText("Nb life actual: ", Arc::Pos(100, 200), Arc::Color::WHITE);
    createText("Actual Score: " + std::to_string(_actualScore), Arc::Pos(100, 300), Arc::Color::WHITE);
    createText("HighScore: " + std::to_string(_highScore) , Arc::Pos(100, 400), Arc::Color::WHITE);
}
