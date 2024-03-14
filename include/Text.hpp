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
        Arc::Color color;
        Arc::Pos pos;
    };
}

#endif /* !TEXT_HPP_ */
