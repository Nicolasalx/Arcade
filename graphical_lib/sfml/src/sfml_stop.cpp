/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sfml_stop
*/

#include "Sfml.hpp"

Arc::Sfml::~Sfml()
{
    this->_window.close();
}
