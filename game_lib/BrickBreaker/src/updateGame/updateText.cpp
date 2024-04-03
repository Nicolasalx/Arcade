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
}