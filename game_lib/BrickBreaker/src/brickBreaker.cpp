/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snake
*/

#include "BrickBreaker.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "BrickBreaker loaded !\n";
}

extern "C"
{
    Arc::IGameModule *entryPoint(void)
    {
        return new Arc::BrickBreaker();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "BrickBreaker unloaded !\n";
}

Arc::BrickBreaker::BrickBreaker()
{
    Enemy enemy;

    this->gameData.enemy.push_back(enemy);

    this->gameData.player.health = 3; // Trouver un moyen d'afficher les 3 coeurs
    _velocity = {2, 8};


    createMap(); // Rename createGame
    // ! Définition du radius et de la vitesse dans le .hpp en define
    // ! Function pour bouger la raquette a gauche ou a droite
    // ! Dans update on parcours la map et on set chaque texte en fonction

    /*
        _clockMove.setCooldown(std::chrono::milliseconds(100));
        _clockMove.start();
    */
}

Arc::BrickBreaker::~BrickBreaker()
{
    std::cout << "BrickBreaker is class destroyed.\n";
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_brickBreaker";
        return name;
    }
}
