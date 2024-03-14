/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Menu
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_

    #include "IGameModule.hpp"
    #include <filesystem>
    #include <set>
    #include "AGameModule.hpp"

namespace Arc
{
    class Menu : public AGameModule
    {
    enum libIsPresent {
        PRESENT,
        NOT_PRESENT
    };
    public:
        Menu();
        ~Menu();

        void init();
        const Arc::GameData &update(const std::vector<Arc::Event> &event);
        void stop();
        const std::string &getName() const;
    private:
        std::string _name = "Menu";
        std::set<std::string> allLibGame = {
            "arcade_menu.so",
            "arcade_snake.so",
            "arcade_pacman.so"
        };

        std::set<std::string> allLibGraphical = {
            {"arcade_ncurses.so"},
            {"arcade_sfml.so"}
        };

        std::set<std::string> mapLibGame;
        std::set<std::string> mapLibGraphical;
    };
}

#endif /* !PACMAN_HPP_ */
