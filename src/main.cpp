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
#include "Arcade.hpp"

int main(int argc, const char *argv[])
{
    try {
        Arc::Arcade arcade(argc, argv);
        arcade.launch();

        Arc::DLLoader<Arc::IGameModule> displayLib("lib/arcade_menu.so");
        Arc::IGameModule *displayInstance = displayLib.getInstance("entryPoint");

        std::cout << "The graphical lib is : " << displayInstance->getName() << '\n';

    } catch (const std::exception &exception) {
        my::log::error(exception.what());
        return 84;
    }
    return 0;
}
