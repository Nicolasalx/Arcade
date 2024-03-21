/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sfml_refresh
*/

#include "Sfml.hpp"
#include "my_tracked_exception.hpp"
#include "SafeDiv.hpp"
#include "DisplayException.hpp"

void Arc::Sfml::appendTextToPool()
{
    ++ this->_textI;
    if (this->_textI >= this->_pool.text.size()) {
        this->_pool.text.emplace_back();
    }
}

void Arc::Sfml::appendFontToPool(const std::string &fontPath)
{
    if (!this->_pool.font.contains(fontPath)) {
        sf::Font font;
        if (!font.loadFromFile(fontPath)) {
            throw Arc::DisplayException("Failed to load: " + fontPath);
        }
        this->_pool.font[fontPath] = font;
    }
}

void Arc::Sfml::appendSpriteToPool()
{
    ++ this->_spriteI;
    if (this->_spriteI >= this->_pool.sprite.size()) {
        this->_pool.sprite.emplace_back();
    }
}

void Arc::Sfml::appendTextureToPool(const std::string &texturePath)
{
    if (!this->_pool.texture.contains(texturePath)) {
        sf::Texture texture;
        if (!texture.loadFromFile(texturePath)) {
            throw Arc::DisplayException("Failed to load: " + texturePath);
        }
        this->_pool.texture[texturePath] = texture;
    }
}

void Arc::Sfml::displayTile(const Arc::Tile &tile)
{
    appendTextureToPool(tile.imagePath);
    appendSpriteToPool();
    sf::Vector2u texture_size = this->_pool.texture.at(tile.imagePath).getSize();

    this->_pool.sprite[_spriteI - 1].setTexture(this->_pool.texture.at(tile.imagePath), true);
    this->_pool.sprite[_spriteI - 1].setPosition(sf::Vector2f(tile.pos.x, tile.pos.y));
    this->_pool.sprite[_spriteI - 1].setScale(sf::Vector2f(
        Arc::safeDiv<double>(tile.size.x, texture_size.x),
        Arc::safeDiv<double>(tile.size.y, texture_size.y)
    ));
    this->_window.draw(this->_pool.sprite[_spriteI - 1]);
}

void Arc::Sfml::displayTileSet(const std::vector<Arc::Tile> &tileSet)
{
    for (const Arc::Tile &tileIt : tileSet)
    {
        displayTile(tileIt);
    }
}

void Arc::Sfml::displayText(const Arc::GameData &gameData)
{
    for (const Arc::Text &textIt : gameData.textSet)
    {
        if (textIt.text.empty()) {
            continue;
        }
        appendFontToPool(textIt.fontPath);
        appendTextToPool();
        this->_pool.text[_textI - 1].setString(textIt.text);
        this->_pool.text[_textI - 1].setFont(this->_pool.font.at(textIt.fontPath));
        this->_pool.text[_textI - 1].setCharacterSize(textIt.size);
        this->_pool.text[_textI - 1].setFillColor(this->_colorBind.at(textIt.color));
        this->_pool.text[_textI - 1].setPosition(sf::Vector2f(textIt.pos.x, textIt.pos.y));
        _window.draw(this->_pool.text[_textI - 1]);
    }
}

void Arc::Sfml::displayPlayer(const Arc::GameData &gameData)
{
    this->displayTileSet(gameData.player.tileSet);
}

void Arc::Sfml::displayEnemy(const Arc::GameData &gameData)
{
    for (const Arc::Enemy &enemyIt : gameData.enemy) {
        this->displayTileSet(enemyIt.tileSet);
    }
}

void Arc::Sfml::displayItem(const Arc::GameData &gameData)
{
    for (const auto &itemIt : gameData.item)
    {
        this->displayTile(itemIt.tile);
    }
}

void Arc::Sfml::refresh(const Arc::GameData &gameData)
{
    if (_window.isOpen()) {
        _window.clear(sf::Color::Black);

        displayTileSet(gameData.tileSet);
        displayText(gameData);
        displayItem(gameData);
        displayEnemy(gameData);
        displayPlayer(gameData);

        _window.display();
    }
    this->_spriteI = 0;
    this->_textI = 0;
    this->_ignoreKey = gameData.player.ignoreKey;
}
