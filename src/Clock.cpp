/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Clock
*/

#include "Clock.hpp"

Arc::Clock::Clock(std::chrono::milliseconds cooldown) : _cooldown(cooldown)
{
}

void Arc::Clock::setCooldown(std::chrono::milliseconds cooldown)
{
    this->_cooldown = cooldown;
}

void Arc::Clock::start()
{
    this->_start = std::chrono::steady_clock::now();
}

bool Arc::Clock::isElapsed() const
{
    return (std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now() - this->_start) >= this->_cooldown);
}

void Arc::Clock::reset()
{
    this->_start = std::chrono::steady_clock::now();
}
