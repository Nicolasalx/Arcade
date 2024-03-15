/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_

    #include "ADisplayModule.hpp"
    #include "ncurses.h"

namespace Arc
{
    class Ncurses: public ADisplayModule
    {
        public:
            Ncurses() = default;
            ~Ncurses() = default;

            void init();
            Arc::Event getEvent();
            void refresh(const Arc::GameData &gameData);
            void stop();
            const std::string &getName() const;

        private:
            std::string _name = "Ncurses";

            std::vector<std::pair<int, Arc::EventType>> _keybind = {
                {'e', Arc::EventType::EXIT},
                {KEY_UP, Arc::EventType::UP},
                {KEY_DOWN, Arc::EventType::DOWN},
                {KEY_LEFT, Arc::EventType::LEFT},
                {KEY_RIGHT, Arc::EventType::RIGHT},
                {'n', Arc::EventType::NEXT_DISPLAY},
                {'g', Arc::EventType::NEXT_GAME},
                {'m', Arc::EventType::BACK_MENU},
                {'r', Arc::EventType::RESTART},
                {'a', Arc::EventType::INTERACT_1},
                {'z', Arc::EventType::INTERACT_2},
                {'\n', Arc::EventType::ENTER}
            };
    };
}

#endif /* !NCURSES_HPP_ */
