/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** randomDouble
*/

#include "BrickBreaker.hpp"

double Arc::BrickBreaker::getRandomPos(double min, double max)
{
    double randomValue = min + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX) / (max - min));
    return randomValue;
}

int Arc::BrickBreaker::getRandomPosToInt(int min, int max)
{
    return min + (std::rand()) / ((RAND_MAX) / (max - min));
}
