/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Lib
*/

#ifndef LIB_HPP_
    #define LIB_HPP_

    #include <vector>
    #include <string>

namespace Arc
{
    struct Lib {
        std::vector<std::string> gamePath;
        std::vector<std::string> graphicalPath;
        std::size_t currentGame;
        std::size_t currentDisplay;
    };
}

#endif /* !LIB_HPP_ */
