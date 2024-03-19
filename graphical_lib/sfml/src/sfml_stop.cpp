/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sfml_stop
*/

#include "Sfml.hpp"

void Arc::Sfml::stop()
{
    this->_window.close();
    this->_stopped = true;
}
