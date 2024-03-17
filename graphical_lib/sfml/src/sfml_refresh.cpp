/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sfml_refresh
*/

#include "Sfml.hpp"
#include "my_tracked_exception.hpp"
#include "SafeDiv.hpp"
#include <iostream>

void Arc::Sfml::appendTextToPool()
{
    ++ this->textCout;
    if (this->textCout >= this->_pool.text.size()) {
        this->_pool.text.emplace_back();
    }
}

void Arc::Sfml::appendFontToPool(const std::string &fontPath)
{
    if (!this->_pool.font.contains(fontPath)) {
        sf::Font font;
        if (!font.loadFromFile(fontPath)) {
            throw my::tracked_exception("Failed to load: " + fontPath);
        }
        this->_pool.font[fontPath] = font;
    }
}

void Arc::Sfml::appendSpriteToPool()
{
    ++ this->spriteCout;
    if (this->spriteCout >= this->_pool.sprite.size()) {
        this->_pool.sprite.emplace_back();
    }
}

void Arc::Sfml::appendTextureToPool(const std::string &texturePath)
{
    if (!this->_pool.texture.contains(texturePath)) {
        sf::Texture texture;
        if (!texture.loadFromFile(texturePath)) {
            throw my::tracked_exception("Failed to load: " + texturePath);
        }
        this->_pool.texture[texturePath] = texture;
    }
}

void Arc::Sfml::displayTileSet(const std::vector<Arc::Tile> &tileSet)
{
    for (size_t i = 0; i < tileSet.size(); ++i)
    {
        appendTextureToPool(tileSet[i].imagePath);
        appendSpriteToPool();
        sf::Vector2u texture_size = this->_pool.texture.at(tileSet[i].imagePath).getSize();

        this->_pool.sprite[i].setTexture(this->_pool.texture.at(tileSet[i].imagePath));
        this->_pool.sprite[i].setPosition(sf::Vector2f(tileSet[i].pos.x, tileSet[i].pos.y));
        this->_pool.sprite[i].setScale(sf::Vector2f(
            Arc::safeDiv<double>(tileSet[i].size.x, texture_size.x),
            Arc::safeDiv<double>(tileSet[i].size.x, texture_size.y)
        ));
        this->_window.draw(this->_pool.sprite[i]);
    }
}

void Arc::Sfml::displayText(const Arc::GameData &gameData)
{
    for (std::size_t i = 0; i < gameData.textSet.size(); ++i)
    {
        appendFontToPool(gameData.textSet[i].fontPath);
        appendTextToPool();
        this->_pool.text[i].setString(gameData.textSet[i].text);
        this->_pool.text[i].setFont(this->_pool.font.at(gameData.textSet[i].fontPath));
        this->_pool.text[i].setCharacterSize(gameData.textSet[i].size);
        this->_pool.text[i].setFillColor(this->_colorBind.at(gameData.textSet[i].color));
        this->_pool.text[i].setPosition(sf::Vector2f(gameData.textSet[i].pos.x, gameData.textSet[i].pos.y));
        _window.draw(this->_pool.text[i]);
    }
}

void Arc::Sfml::displayPlayer(const Arc::GameData &gameData)
{
    this->displayTileSet(gameData.player.tileSet);
}

void Arc::Sfml::refresh(const Arc::GameData &gameData)
{
    if (_window.isOpen()) {
        _window.clear(sf::Color::Black);

        displayTileSet(gameData.tileSet);
        displayText(gameData);
        displayPlayer(gameData);

        _window.display();
    }
    this->spriteCout = 0;
    this->textCout = 0;
    this->_ignoreKey = gameData.player.ignoreKey;
}
