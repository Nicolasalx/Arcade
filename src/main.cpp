/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** main
*/

#include <iostream>
#include <memory>
#include <stdexcept>
#include "my_log.hpp"
#include "DLLoader.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

int main(int argc, const char *argv[])
{
    try {
        Arc::DLLoader<Arc::IGameModule> PacmanLib("./lib/arcade_pacman.so");
        Arc::IGameModule *pacman = PacmanLib.getInstance("entryPoint");

        Arc::DLLoader<Arc::IGameModule> SnakeLib("./lib/arcade_snake.so");
        Arc::IGameModule *snake = SnakeLib.getInstance("entryPoint");

        Arc::DLLoader<Arc::IDisplayModule> NcursesLib("./lib/arcade_ncurses.so");
        Arc::IDisplayModule *ncurses = NcursesLib.getInstance("entryPoint");

        Arc::DLLoader<Arc::IDisplayModule> SfmlLib("./lib/arcade_sfml.so");
        Arc::IDisplayModule *sfml = SfmlLib.getInstance("entryPoint");

        std::cout << "The game is: " << pacman->getName() << "\n";
        std::cout << "The game is: " << snake->getName() << "\n";

        std::cout << "The game is: " << ncurses->getName() << "\n";
        std::cout << "The game is: " << sfml->getName() << "\n";


    } catch (const std::exception &exception) {
        my::log::error(exception.what());
        return 84;
    }
    return 0;
}
