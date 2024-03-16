/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** ncurses_init
*/

#include "Ncurses.hpp"

void Arc::Ncurses::init()
{
    initscr();
    noecho();
    curs_set(0);
    timeout(0);
    keypad(stdscr, TRUE);
    start_color();
    for (const auto &currentCol : this->_colorBind) {
        init_pair(currentCol.second.pair, currentCol.second.color, COLOR_BLACK);
    }
}
