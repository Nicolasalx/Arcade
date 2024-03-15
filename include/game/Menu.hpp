/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_

    #include <filesystem>
    #include <set>
    #include <vector>
    #include "AGameModule.hpp"
    #include "Pos.hpp"
    #include "DLLoader.hpp"
    #include <algorithm>

    #define USERNAME "Username"
    #define VALIDATE "Valider"
    #define GAME_LIST "Games list:"
    #define GRAPHICAL_LIST "Graphicals list:"

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
        std::string getFileName(const std::string &name);

        void selectNextChoice();
        void selectPrevChoice();
        void validateChoice(const std::string &filename);

        void modifyAllTextColor();

        std::string _name = "arcade_D_menu";
        std::vector<std::string> _mapLibGame;
        std::vector<std::string> _mapLibGraphical;
        cursorPlace_t _cursorPlace;
        std::vector<Arc::Text> _allTextSelectable;
    };
}

#endif /* !MENU_HPP_ */
