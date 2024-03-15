/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Tile
*/

#ifndef TILE_HPP_
    #define TILE_HPP_

    #include <string>
    #include "ColorEnum.hpp"

namespace Arc
{
    struct Tile
    {
        std::string imagePath;
        char c = '_';
        Arc::Color color = Arc::Color::BLACK;
    };
}

#endif /* !TILE_HPP_ */
