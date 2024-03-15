/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_

    #include "ADisplayModule.hpp"

namespace Arc
{
    class Ncurses: public ADisplayModule
    {
        public:
            Ncurses() = default;
            ~Ncurses() = default;

            void init();
            std::vector<Arc::Event> getEvent();
            void refresh(const Arc::GameData &gameData);
            void stop();
            const std::string &getName() const;

        protected:
        private:
            std::string name = "arcade_G_ncurses";
    };
}

#endif /* !NCURSES_HPP_ */
