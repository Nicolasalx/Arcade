/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sfml_init
*/

#include "Sfml.hpp"
#include "DisplayException.hpp"
#include <csignal>

static void abort_sfml(int)
{
    throw Arc::DisplayException("sfml fail to create window.");
}

Arc::Sfml::Sfml()
{
    std::signal(SIGABRT, abort_sfml);
    this->_window.create(sf::VideoMode(1920, 1080), "SFML Arcade");
}
