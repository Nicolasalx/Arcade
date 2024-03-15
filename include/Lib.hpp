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
        ASK_CURRENT_GAME,
        ASK_CURRENT_DISPLAY,
        NEW_SELECTION
    };

    struct Lib {
        std::vector<std::string> gamePath;
        std::vector<std::string> graphicalPath;
        int currentGame = -1;
        int currentDisplay = -1;
        Arc::LibState libState = Arc::LibState::NOT_INIT;
    };
}

#endif /* !LIB_HPP_ */
