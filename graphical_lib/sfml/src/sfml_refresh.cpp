/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sfml_refresh
*/

#include "Sfml.hpp"
#include "my_tracked_exception.hpp"
#include "SafeDiv.hpp"

void Arc::Sfml::displayTileSet(const Arc::GameData &gameData)
{
    for (size_t i = 0; i < gameData.tileSet.size(); ++i)
    {
        sf::Texture texture;
        if (!texture.loadFromFile(gameData.tileSet[i].imagePath)) {
            my::tracked_exception("Failed to load: " + gameData.tileSet[i].imagePath);
        }

        sf::Sprite sprite(texture);

        sf::Vector2u texture_size = texture.getSize();
        sprite.setPosition(sf::Vector2f(gameData.tileSet[i].pos.x, gameData.tileSet[i].pos.y));
        sprite.setScale(sf::Vector2f(Arc::safeDiv<double>(gameData.tileSet[i].size.x, texture_size.x), Arc::safeDiv<double>(gameData.tileSet[i].size.x, texture_size.y)));
        this->_window.draw(sprite);
    }
}

void Arc::Sfml::displayText(const Arc::GameData &gameData)
{
    for (std::size_t i = 0; i < gameData.textSet.size(); ++i)
    {
        if (!this->_fontList.contains(gameData.textSet[i].fontPath)) {
            sf::Font font;
            if (!font.loadFromFile(gameData.textSet[i].fontPath)) {
                throw my::tracked_exception("Failed to load: " + gameData.textSet[i].fontPath);
            }
            this->_fontList[gameData.textSet[i].fontPath] = font;
        }
        if (i >= this->_textList.size()) {
            this->_textList.emplace_back();
        }
        this->_textList[i].setString(gameData.textSet[i].text);
        this->_textList[i].setFont(this->_fontList.at(gameData.textSet[i].fontPath));
        this->_textList[i].setCharacterSize(gameData.textSet[i].size);
        this->_textList[i].setFillColor(this->_colorBind.at(gameData.textSet[i].color));
        this->_textList[i].setPosition(sf::Vector2f(gameData.textSet[i].pos.x, gameData.textSet[i].pos.y));
        _window.draw(this->_textList[i]);
    }
}

void Arc::Sfml::refresh(const Arc::GameData &gameData)
{
    if (_window.isOpen()) {
        _window.clear(sf::Color::Black);

        displayTileSet(gameData);
        displayText(gameData);

        _window.display();
    }
    this->_ignoreKey = gameData.player.ignoreKey;
}
