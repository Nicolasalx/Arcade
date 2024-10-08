/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** ncurses_getEvent
*/

#include "Ncurses.hpp"

void Arc::Ncurses::putEventInBuffer(int c, Arc::Event &event)
{
    if (c == '\n') {
        event.eventType.push_back(Arc::EventType::ENTER);
    } else if (c < 128) {
        event.buffer += c;
    }
}

void Arc::Ncurses::putEventInEventList(int c, Arc::Event &event)
{
    for (const auto &currentKey : this->_keyBind) {
        if (c == currentKey.first) {
            event.eventType.push_back(currentKey.second);
        }
    }
}

Arc::Event Arc::Ncurses::getEvent()
{
    Arc::Event event;
    int c = getch();

    while (c != ERR) {
        if (this->_ignoreKey) {
            this->putEventInBuffer(c, event);
        } else {
            this->putEventInEventList(c, event);
        }
        c = getch();
    }
    return event;
}
