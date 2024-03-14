/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Text
*/

#ifndef TEXT_HPP_
    #define TEXT_HPP_

    #include <string>
    #include <ColorEnum.hpp>
    #include <Pos.hpp>

namespace Arc
{
    struct Text
    {
        std::string text;
        std::string fontPath;
        Arc::Color color = Arc::Color::WHITE;
        Arc::Pos pos;
        std::size_t size = 0;
    };
}

#endif /* !TEXT_HPP_ */
