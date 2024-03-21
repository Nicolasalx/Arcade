/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** ncurses_init
*/

#include "Ncurses.hpp"
#include "DisplayException.hpp"

Arc::Ncurses::Ncurses()
{
    if (!initscr()) {
        throw Arc::DisplayException("ncurses fail to init the screen.");
    }
    noecho();
    curs_set(0);
    timeout(0);
    keypad(stdscr, TRUE);
    start_color();
    for (const auto &currentCol : this->_colorBind) {
        init_pair(currentCol.second.pair, currentCol.second.color, COLOR_BLACK);
    }
}
