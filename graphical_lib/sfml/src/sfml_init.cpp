/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sfml_init
*/

#include "Sfml.hpp"

void Arc::Sfml::init()
{
    this->_window.create(sf::VideoMode(1920, 1080), "SFML Arcade");
}
