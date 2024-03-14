/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Menu
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_

    #include <filesystem>
    #include <set>
    #include "AGameModule.hpp"
    #include "Pos.hpp"

struct cursorPlace_t {
    std::string libInSelection;
    std::string libSelectionned;
};

namespace Arc
{
    class Menu : public AGameModule
    {
    public:
        Menu();
        ~Menu();

        const Arc::GameData init();
        const Arc::GameData &update(const std::vector<Arc::Event> &event);
        void stop();
        const std::string &getName() const;
        void createTextWithLib(const std::string &libGame, size_t &posY);
        void getLibFromDirectory();

    private:
        std::string _name = "Menu";
        std::set<std::string> _allLibGame = {
            "arcade_menu.so",
            "arcade_snake.so",
            "arcade_pacman.so"
        };
        std::set<std::string> _allLibGraphical = {
            "arcade_ncurses.so",
            "arcade_sfml.so"
        };
        std::set<std::string> _mapLibGame;
        std::set<std::string> _mapLibGraphical;
        cursorPlace_t _cursorPlace;
    };
}

#endif /* !PACMAN_HPP_ */
