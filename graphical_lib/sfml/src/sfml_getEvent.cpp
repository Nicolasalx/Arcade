/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sfml_getEvent
*/

#include "Sfml.hpp"

Arc::Event Arc::Sfml::getEvent()
{
    Arc::Event event;

    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed) {
            event.eventType.push_back(Arc::EventType::EXIT);
        }
        if (this->_ignoreKey) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                event.eventType.push_back(Arc::EventType::ENTER);
            }
            else if (this->_event.type == sf::Event::TextEntered
            && this->_event.text.unicode < 128) {
                event.buffer += this->_event.text.unicode;
            }
        } else {
            for (const auto &currentKey : this->_keyBind) {
                if (sf::Keyboard::isKeyPressed(currentKey.first)) {
                    event.eventType.push_back(currentKey.second);
                }
            }
        }
    }
    return event;
}
