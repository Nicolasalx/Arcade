/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** updateText
*/

#include "BrickBreaker.hpp"

void Arc::BrickBreaker::updateText()
{
    this->gameData.textSet.at(2).text = "Actual Score: " + std::to_string(_actualScore);

    //createText("Nb life actual: ", Arc::Pos(100, 500), Arc::Color::WHITE);
    //createText("Actual Score: " + std::to_string(_actualScore), Arc::Pos(100, 700), Arc::Color::WHITE);
    //createText("HighScore: " + std::to_string(_highScore) , Arc::Pos(100, 900), Arc::Color::WHITE);
}