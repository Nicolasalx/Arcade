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
        std::cout << "entry point Ncurses !\n";
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
}

std::vector<Arc::Event> Arc::Ncurses::getEvent()
{
    std::vector<Arc::Event> event;
    int c = getch();
    while (c != ERR) {
        if (c == 'e') {
            event.push_back(Arc::Event::EXIT);
        } else if (c == KEY_UP) {
            event.push_back(Arc::Event::UP);
        } else if (c == KEY_DOWN) {
            event.push_back(Arc::Event::DOWN);
        } else if (c == KEY_RIGHT) {
            event.push_back(Arc::Event::RIGHT);
        } else if (c == KEY_LEFT) {
            event.push_back(Arc::Event::LEFT);
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

    for (const auto &currentText : gameData.textSet) {
        mvprintw(currentText.pos.y / 1080.0 * size_y, currentText.pos.x / 1920.0 * size_x, currentText.text.c_str());
    }
    ::refresh();
}

void Arc::Ncurses::stop()
{
    endwin();
}

const std::string &Arc::Ncurses::getName() const
{
    return this->_name;
}

extern "C"
{
    const char *getName()
    {
        static const char name[] = "arcade_D_ncurses";
        return name;
    }
}
