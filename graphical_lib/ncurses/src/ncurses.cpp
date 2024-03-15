/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Ncurses
*/

#include <iostream>
#include "Ncurses.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "Ncurses loaded !\n";
}

extern "C"
{
    Arc::IDisplayModule *entryPoint(void)
    {
        return new Arc::Ncurses();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Ncurses unloaded !\n";
}

void Arc::Ncurses::init()
{
    initscr();
    noecho();
    curs_set(0);
    timeout(0);
    keypad(stdscr, TRUE);
    start_color();
    for (const auto &currentCol : this->_colorBind) {
        init_color(currentCol.second.color, currentCol.second.r, currentCol.second.g, currentCol.second.b);
        init_pair(currentCol.second.pair, currentCol.second.color, COLOR_BLACK);
    }
}

Arc::Event Arc::Ncurses::getEvent()
{
    Arc::Event event;
    int c = getch();

    while (c != ERR) {
        if (this->_ignoreKey) {
            if (c == '\n') {
                event.eventType.push_back(Arc::EventType::ENTER);
            } else if (c < 128) {
                event.buffer += c;
            }
        } else {
            for (const auto &currentKey : this->_keyBind) {
                if (c == currentKey.first) {
                    event.eventType.push_back(currentKey.second);
                }
            }
        }
        c = getch();
    }
    return event;
}

void Arc::Ncurses::refresh(const Arc::GameData &gameData)
{
    int size_x;
    int size_y;
    getmaxyx(stdscr, size_y, size_x);
    clear();

    for (const auto &currentText : gameData.textSet) {
        attron(COLOR_PAIR(this->_colorBind.at(currentText.color).pair));
        mvprintw(currentText.pos.y / 1080.0 * size_y,
            currentText.pos.x / 1920.0 * size_x, currentText.text.c_str());
        attroff(COLOR_PAIR(this->_colorBind.at(currentText.color).pair));
    }
    ::refresh();
    this->_ignoreKey = gameData.player.ignoreKey;
}

void Arc::Ncurses::stop()
{
    endwin();
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_D_ncurses";
        return name;
    }
}
