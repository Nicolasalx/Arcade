/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** arcade
*/

#include "Arcade.hpp"
#include "my_tracked_exception.hpp"

Arc::Arcade::Arcade(int argc, char **argv)
{
    if (argc != 2) {
        throw my::tracked_exception("Invalide nb of arg\n\n"
           "Usage: ./arcade graphical_lib.so\n\n"
           "\tgraphical_lib.so is a dynamic library that"
           "implement all the method of IDisplayModule\n\n");
    }
    this->graphicalLib = std::string(argv[1]);
}

void Arc::Arcade::lauch()
{

}
