/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Menu
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_

    #include <filesystem>
    #include <vector>
    #include "AGameModule.hpp"
    #include "Pos.hpp"
    #include "DLLoader.hpp"

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

        void init();
        const Arc::GameData &update(const std::vector<Arc::Event> &event);
        void stop();
        const std::string &getName() const;
        void createTextWithLib(const std::string &libGame, Pos pos);
        void getLibFromDirectory();
        void selectTypeLib(const std::string &filename);

    private:
        std::string _name = "arcade_D_menu";
        std::vector<std::string> _mapLibGame;
        std::vector<std::string> _mapLibGraphical;
        cursorPlace_t _cursorPlace;
        std::vector<Arc::Text> _allText;
    };
}

#endif /* !PACMAN_HPP_ */
