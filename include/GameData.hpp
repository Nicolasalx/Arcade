/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** GameData
*/

#ifndef GAMEDATA_HPP_
    #define GAMEDATA_HPP_

    #include <vector>
    #include "Tile.hpp"
    #include "Text.hpp"
    #include "Player.hpp"
    #include "Item.hpp"
    #include "Enemy.hpp"

namespace Arc
{
    struct GameData
    {
        std::vector<std::vector<Arc::Tile>> tileSet;
        std::vector<Arc::Text> textSet;
        Arc::Player player;
        std::vector<Arc::Enemy> item;
        std::vector<Arc::Item> item;
    };
}

#endif /* !GAMEDATA_HPP_ */
