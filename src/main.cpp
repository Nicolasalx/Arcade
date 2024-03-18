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
#include "FrameRate.hpp"
#include "DisplayException.hpp"

int main(int argc, const char *argv[])
{
    Arc::Arcade arcade;
    Arc::FrameRate::setFrameRate(30);

    try {
        arcade.start(argc, argv);
        arcade.launch();
        arcade.loop();
    } catch (const std::exception &exception) {
        my::log::error(exception.what());
        return 84;
    }
    return 0;
}
