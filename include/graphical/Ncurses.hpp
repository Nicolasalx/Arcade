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
    #include "ColorEnum.hpp"
    #include <map>

namespace Arc
{
    struct NursesColor {
        short pair;
        short color;
        short r;
        short g;
        short b;
    };

    class Ncurses: public ADisplayModule
    {
        public:
            Ncurses() = default;
            ~Ncurses() = default;

            void init();
            Arc::Event getEvent();
            void refresh(const Arc::GameData &gameData);
            void stop();

        private:
            std::vector<std::pair<int, Arc::EventType>> _keyBind = {
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
            std::map<Arc::Color, Arc::NursesColor> _colorBind = {
                {Arc::Color::WHITE, {1, COLOR_WHITE, 1000, 1000, 1000}},
                {Arc::Color::RED, {2, COLOR_RED, 1000, 0, 0}},
                {Arc::Color::GREEN, {3, COLOR_GREEN, 0, 1000, 0}},
                {Arc::Color::YELLOW, {4, COLOR_YELLOW, 1000, 1000, 0}},
                {Arc::Color::BLUE, {5, COLOR_BLUE, 0, 0, 1000}},
                {Arc::Color::MAGENTA, {6, COLOR_MAGENTA, 1000, 0, 1000}},
                {Arc::Color::CYAN, {7, COLOR_CYAN, 0, 1000, 1000}},
                {Arc::Color::BLACK, {8, COLOR_BLACK, 0, 0, 0}}
            };
    };
}

#endif /* !NCURSES_HPP_ */
