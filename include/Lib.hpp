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
    enum class LibState {
        NOT_INIT,
        CURRENT_NOT_INIT,
        NEW_SELECTION
    };

    struct LibInfo {
        std::string path;
        std::string name;
    };

    struct Lib {
        std::vector<Arc::LibInfo> game;
        std::vector<Arc::LibInfo> graphical;
        int currentGame = -1;
        int currentDisplay = -1;
        Arc::LibState libState = Arc::LibState::NOT_INIT;
    };
}

#endif /* !LIB_HPP_ */
