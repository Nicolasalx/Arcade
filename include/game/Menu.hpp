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
    #include <vector>
    #include "AGameModule.hpp"
    #include "Pos.hpp"
    #include "DLLoader.hpp"

struct cursorPlace_t {
    std::size_t elemInSelect;
    std::size_t gameLib;
    std::size_t graphicalLib;
};

namespace Arc
{
    class Menu : public AGameModule
    {
    enum isSelectable_e {
        SELECTABLE,
        NOT_SELECTABLE
    };

    public:
        Menu();
        ~Menu();

        void init();
        const Arc::GameData &update(const Arc::Event &event);
        void stop();
        void createTextWithLib(const std::string &name, Pos pos, enum isSelectable_e isSelectable);
        void getLibFromDirectory();
        void selectTypeLib(const std::string &filename);
        std::string defineNewName(const std::string &name);

        void selectNextChoice();
        void selectPrevChoice();
        void validateChoice();

        std::string _name = "arcade_D_menu";
        std::vector<std::string> _mapLibGame;
        std::vector<std::string> _mapLibGraphical;
        cursorPlace_t _cursorPlace;
        std::vector<std::pair<Arc::Text, isSelectable_e>> _allTextSelectable;
    };
}

#endif /* !PACMAN_HPP_ */
