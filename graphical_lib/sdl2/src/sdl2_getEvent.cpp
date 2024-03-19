/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Sdl2_getEvent
*/

#include "Sdl2.hpp"

Arc::Event Arc::Sdl2::getEvent()
{
    Arc::Event event;

    while (SDL_PollEvent(&this->_event)) {
        if (this->_event.type == SDL_QUIT) {
            event.eventType.push_back(Arc::EventType::EXIT);
        } else if (this->_event.type == SDL_KEYDOWN) {

            if (this->_ignoreKey) {
                if (this->_event.key.keysym.sym == SDLK_RETURN) {
                    event.eventType.push_back(Arc::EventType::ENTER);
                }
                else if (this->_event.key.keysym.sym < 128) {
                    event.buffer += this->_event.key.keysym.sym;
                }
            } else {
                for (const auto &currentKey : this->_keyBind) {
                    if (this->_event.key.keysym.sym == currentKey.first) {
                        event.eventType.push_back(currentKey.second);
                    }
                }
            }
        }
    }
    return event;
}
