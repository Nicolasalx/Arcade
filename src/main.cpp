/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** main
*/

#include <iostream>
#include <memory>
#include <stdexcept>
#include "mylib.hpp"

int main(int argc, const char *argv[])
{
    try {
        // ! code
    } catch (const std::exception &exception) {
        my::log::error(exception.what());
        return 84;
    }
    return 0;
}
