/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** ncurses_stop
*/

#include "Ncurses.hpp"

void Arc::Ncurses::stop()
{
    endwin();
    reset_shell_mode();
    this->_stopped = true;
}
