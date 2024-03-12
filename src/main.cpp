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

int main(int argc, const char *argv[])
{
    try {
        arc::DLLoader<IDisplayModule> GameLib("./lib/arcade_pacman.so");
        IDisplayModule *game = GameLib.getInstance("entryPoint");

        std::cout << "The game is: " << game->getName() << "\n";

    } catch (const std::exception &exception) {
        my::log::error(exception.what());
        return 84;
    }
    return 0;
}
