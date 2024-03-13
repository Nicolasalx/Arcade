/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Menu
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_

    #include "IGameModule.hpp"

namespace Arc
{
    class Menu : public IGameModule
    {
    public:
        Menu();
        ~Menu();

        void init();
        const Arc::GameData &update(const std::vector<Arc::Event> &event);
        void stop();
        const std::string &getName() const;
    private:
        std::string name = "Menu";
    };
}

#endif /* !PACMAN_HPP_ */
