/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** main
*/

#include <stdexcept>
#include "my_log.hpp"
#include "Arcade.hpp"
#include "FrameRate.hpp"
#include "DisplayException.hpp"
#include "GameException.hpp"

int main(int argc, const char *argv[])
{
    Arc::Arcade arcade;
    Arc::FrameRate::setFrameRate(60);

    try {
        arcade.start(argc, argv);
        arcade.launch();
        arcade.loop();
    } catch (const Arc::DisplayException &e) {
        my::log::error(e.what());
        return 84;
    } catch (const Arc::GameException &e) {
        my::log::error(e.what());
        return 84;
    } catch (const std::exception &exception) {
        my::log::error(exception.what());
        return 84;
    }
    return 0;
}
