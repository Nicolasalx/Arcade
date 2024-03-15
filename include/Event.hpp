/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Event
*/

#ifndef EVENT_HPP_
    #define EVENT_HPP_

    #include "EventType.hpp"
    #include <string>
    #include <vector>

namespace Arc
{
    struct Event
    {
        std::vector<Arc::EventType> eventType;
        std::string buffer;
    };
}

#endif /* !EVENT_HPP_ */
