/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Enemy
*/

#ifndef ENEMY_HPP_
    #define ENEMY_HPP_

    #include "Pos.hpp"

namespace Arc
{
    struct Enemy
    {
        Arc::Pos pos;
        int health;
    };
}

#endif /* !ENEMY_HPP_ */
