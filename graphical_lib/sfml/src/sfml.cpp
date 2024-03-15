/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sfml
*/

#include <iostream>
#include "Sfml.hpp"
#include "my_tracked_exception.hpp"

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
    std::vector<Arc::Event> event;

    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            event.push_back(Arc::Event::KEY_E);
        }
    }
    return event;
}

void Arc::Sfml::refresh(const Arc::GameData &gameData)
{
    if (_window.isOpen()) {
        _window.clear(sf::Color::Black);

        for (std::size_t i = 0; i < gameData.textSet.size(); ++i) {

            if (!this->_fontList.contains(gameData.textSet[i].fontPath)) {
                sf::Font font;
                if (!font.loadFromFile(gameData.textSet[i].fontPath)) {
//                    throw my::tracked_exception("Failed to load: " + gameData.textSet[i].fontPath);
                    return;
                }
                this->_fontList[gameData.textSet[i].fontPath] = font;
            }

            if (i >= this->_textList.size()) {
                this->_textList.emplace_back();
            }
            
            this->_textList[i].setString(gameData.textSet[i].text);
            this->_textList[i].setFont(this->_fontList.at(gameData.textSet[i].fontPath));
            this->_textList[i].setCharacterSize(gameData.textSet[i].size);
            this->_textList[i].setFillColor(sf::Color::White);
            this->_textList[i].setPosition(sf::Vector2f(gameData.textSet[i].pos.x, gameData.textSet[i].pos.y));
            _window.draw(this->_textList[i]);
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
