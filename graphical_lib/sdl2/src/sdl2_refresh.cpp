/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Sdl2_refresh
*/

#include "Sdl2.hpp"
#include "DisplayException.hpp"

void Arc::Sdl2::appendTextureToPool(const std::string &texturePath)
{
    if (!this->_pool.texture.contains(texturePath)) {
        SDL_Texture *texture = IMG_LoadTexture(this->_renderer, texturePath.c_str());
        if (!texture) {
            throw Arc::DisplayException("Failed to load: " + texturePath);
        }
        this->_pool.texture[texturePath] = texture;
    }
}

void Arc::Sdl2::displayTile(const Arc::Tile &tile)
{
    appendTextureToPool(tile.imagePath);

    int sizeX = 0;
    int sizeY = 0;
    SDL_QueryTexture(this->_pool.texture.at(tile.imagePath), nullptr, nullptr, &sizeX, &sizeY);

    SDL_Rect destRect = {static_cast<int>(tile.pos.x), static_cast<int>(tile.pos.y),
        static_cast<int>(tile.size.x), static_cast<int>(tile.size.y)};
    SDL_RenderCopy(this->_renderer, this->_pool.texture.at(tile.imagePath), nullptr, &destRect);
}

void Arc::Sdl2::displayTileSet(const std::vector<Arc::Tile> &tileSet)
{
    for (const Arc::Tile &tileIt : tileSet) {
        this->displayTile(tileIt);
    }
}

void Arc::Sdl2::displayPlayer(const Arc::GameData &gameData)
{
    this->displayTileSet(gameData.player.tileSet);
}

void Arc::Sdl2::displayEnemy(const Arc::GameData &gameData)
{
    for (const Arc::Enemy &enemyIt : gameData.enemy) {
        this->displayTileSet(enemyIt.tileSet);
    }
}

void Arc::Sdl2::displayItem(const Arc::GameData &gameData)
{
    for (const Arc::Item &itemIt : gameData.item)
    {
        this->displayTile(itemIt.tile);
    }
}

void Arc::Sdl2::refresh(const Arc::GameData &gameData)
{
    SDL_RenderClear(this->_renderer);

    displayTileSet(gameData.tileSet);
    displayText(gameData);
    displayPlayer(gameData);
    displayEnemy(gameData);
    displayItem(gameData);

    SDL_RenderPresent(this->_renderer);

    this->_surfaceI = 0;
    this->_textTextureI = 0;
    this->_ignoreKey = gameData.player.ignoreKey;
}
