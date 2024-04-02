/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include "Pos.hpp"
    #include <vector>

namespace Arc
{
    struct Player
    {
        Arc::Pos pos;
        int health = 0;
        std::string userName;
        std::size_t score = 0;
        std::vector<Tile> tileSet;
        bool ignoreKey = false;
    };
}

#endif /* !PLAYER_HPP_ */
