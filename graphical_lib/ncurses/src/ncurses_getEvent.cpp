/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** ncurses_getEvent
*/

#include "Ncurses.hpp"

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
