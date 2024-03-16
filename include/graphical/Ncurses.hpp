/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_

    #include "ADisplayModule.hpp"
    #include <ncurses.h>
    #include "ColorEnum.hpp"
    #include <map>

namespace Arc
{
    struct NcursesColor {
        short pair = 0;
        short color = 0;
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
        void displayTileSet(const Arc::GameData &gameData);
        void displayText(const Arc::GameData &gameData);
        void safeMVPrintW(int x, int y, const std::string &str);

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
        std::map<Arc::Color, Arc::NcursesColor> _colorBind = {
            {Arc::Color::WHITE,   {1, 15}},
            {Arc::Color::RED,     {2, 9}},
            {Arc::Color::GREEN,   {3, 10}},
            {Arc::Color::YELLOW,  {4, 11}},
            {Arc::Color::BLUE,    {5, 12}},
            {Arc::Color::MAGENTA, {6, 13}},
            {Arc::Color::CYAN,    {7, 14}},
            {Arc::Color::BLACK,   {8, 0}}
        };
    };
}

#endif /* !NCURSES_HPP_ */
