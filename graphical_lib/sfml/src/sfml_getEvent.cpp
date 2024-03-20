/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sfml_getEvent
*/

#include "Sfml.hpp"

void Arc::Sfml::putEventInBuffer(Arc::Event &event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        event.eventType.push_back(Arc::EventType::ENTER);
    }
    else if (this->_event.type == sf::Event::TextEntered
    && this->_event.text.unicode < 128) {
        event.buffer += this->_event.text.unicode;
    }
}

void Arc::Sfml::putEventInEventList(Arc::Event &event)
{
    for (const auto &currentKey : this->_keyBind) {
        if (sf::Keyboard::isKeyPressed(currentKey.first)) {
            event.eventType.push_back(currentKey.second);
        }
    }
}

Arc::Event Arc::Sfml::getEvent()
{
    Arc::Event event;

    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed) {
            event.eventType.push_back(Arc::EventType::EXIT);
        }
        if (this->_ignoreKey) {
            this->putEventInBuffer(event);
        } else {
            this->putEventInEventList(event);
        }
    }
    return event;
}
