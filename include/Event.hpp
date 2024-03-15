/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Event
*/

#ifndef EVENT_HPP_
    #define EVENT_HPP_

namespace Arc
{
    enum class Event {
        KEY_PRESSED,
        KEY_RELEASED,
        MOUSE_BUTTON_PRESSED,
        MOUSE_BUTTON_RELEASED,
        SPACE,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ENTER,
        KEY_E
    };
}

#endif /* !EVENT_HPP_ */
