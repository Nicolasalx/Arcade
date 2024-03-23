/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** init
*/

#include "BrickBreaker.hpp"

Arc::BrickBreaker::BrickBreaker()
{
    Enemy enemy;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    this->gameData.enemy.push_back(enemy);

    this->gameData.player.health = 3; // Trouver un moyen d'afficher les 3 coeurs
    _velocity = {getRandomPos(-5, 5), 8};

    createMap();
    createAllTexts();

    /*
        _clockMove.setCooldown(std::chrono::milliseconds(100));
        _clockMove.start();
    */
}
