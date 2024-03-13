/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include "Pos.hpp"

namespace Arc
{
    struct Player
    {
        Arc::Pos pos;
        int health;
    };
}

#endif /* !PLAYER_HPP_ */
