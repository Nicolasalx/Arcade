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

    #define USERNAME "Username:"
    #define VALIDATE "Valider"
    #define GAME_LIST "Games list:"
    #define GRAPHICAL_LIST "Graphicals list:"
    #define IDX_LIST_START 2

struct cursorPlace_t {
    std::size_t elemInSelect = 0;
    std::size_t gameLib = 0;
    std::size_t graphicalLib = 0;
};

namespace Arc
{
    class Menu : public AGameModule
    {
    enum IsSelectable {
        SELECTABLE,
        NOT_SELECTABLE
    };

    public:
        Menu();
        ~Menu() override;

        const Arc::GameData &update(const Arc::Event &event) override;

    private:
        void createAllText();
        void createTextWithLib(const std::string &name, Pos pos, IsSelectable isSelectable);
        void getLibFromDirectory();
        void selectTypeLib(const std::string &filename);
        static std::string getFileName(const std::string &filepath);
        void selectNextChoice();
        void selectPrevChoice();
        void validateChoice(const std::string &filename);
        void defineIdxCursor();
        void modifyAllTextColor();
        void defineNewCursorGame(const std::string &filename);
        void defineNewCursorGraphical(const std::string &filename);
        void handleValidation(const std::string &filename);
        void handleActionUsername(const std::string &filename);
        void fillUsername(const std::string &bufferEvent);
        void setDefaultName();
        static void detectDelete(const std::string &bufferEvent, bool &isADeleteChar);

        std::vector<std::string> _mapLibGame;
        std::vector<std::string> _mapLibGraphical;
        cursorPlace_t _cursorPlace;
        std::vector<Arc::Text> _allTextSelectable;
    };
}

#endif /* !MENU_HPP_ */
