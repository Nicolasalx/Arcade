/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sfml
*/

#include <iostream>
#include "Sfml.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "Sfml loaded !\n";
}

extern "C"
{
    Arc::IDisplayModule *entryPoint(void)
    {
        std::cout << "entry point Sfml !\n";
        return new Arc::Sfml();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Sfml unloaded !\n";
}

void Arc::Sfml::init()
{
    this->_window.create(sf::VideoMode(1920, 1080), "SFML Arcade");
}

std::vector<Arc::Event> Arc::Sfml::getEvent()
{
    std::cout << "Sfml get event.\n";
    return std::vector<Arc::Event>();
}

void Arc::Sfml::refresh(const Arc::GameData &gameData)
{
    if (_window.isOpen()) {
        _window.clear(sf::Color::Black);

        for (size_t i = 0; i < gameData.textSet.size(); ++i) {

            sf::Font font;
            if (!font.loadFromFile(gameData.textSet[i].fontPath)) {
                return;
            }

            sf::Text text(gameData.textSet[i].text, font, 20);
            text.setFillColor(sf::Color::White);
            text.setStyle(sf::Text::Regular);
            text.setPosition(sf::Vector2f(gameData.textSet[i].pos.x, gameData.textSet[i].pos.y));
            _window.draw(text);
        }

        _window.display();
    }
    std::cout << "Refresh Sfml ...";
}

void Arc::Sfml::stop()
{
    this->_window.close();
    std::cout << "Sfml is stopped.\n";
}

const std::string &Arc::Sfml::getName() const
{
    return this->name;
}
