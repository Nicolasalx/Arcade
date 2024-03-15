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
}

Arc::Event Arc::Ncurses::getEvent()
{
    Arc::Event event;
    int c = getch();
    while (c != ERR) {
        if (c == 'e') {
            event.eventType.push_back(Arc::EventType::EXIT);
        } else if (c == KEY_UP) {
            event.eventType.push_back(Arc::EventType::UP);
        } else if (c == KEY_DOWN) {
            event.eventType.push_back(Arc::EventType::DOWN);
        } else if (c == KEY_RIGHT) {
            event.eventType.push_back(Arc::EventType::RIGHT);
        } else if (c == KEY_LEFT) {
            event.eventType.push_back(Arc::EventType::LEFT);
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
    const std::string &getName()
    {
        static const std::string name = "arcade_D_ncurses";
        return name;
    }
}
