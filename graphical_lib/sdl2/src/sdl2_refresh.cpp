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

void Arc::Sdl2::appendFontToPool(const std::string &fontPath)
{
    if (!this->_pool.font.contains(fontPath)) {
        TTF_Font *font = TTF_OpenFont(fontPath.c_str(), 10);
        if (!font) {
            throw Arc::DisplayException("Failed to load: " + fontPath);
        }
        this->_pool.font[fontPath] = font;
    }
}

void Arc::Sdl2::appendSurfaceToPool()
{
    ++ this->_surfaceI;
    if (this->_surfaceI >= this->_pool.surface.size()) {
        this->_pool.surface.emplace_back();
    }
    // if (!this->_pool.surface.contains(fontPath)) {
    //     SDL_Surface *surface = TTF_OpenFont(fontPath.c_str(), size);
    //     if (!surface) {
    //         throw Arc::DisplayException("Failed to load: " + fontPath);
    //     }
    //     this->_pool.font[fontPath] = surface;
    // }
}

void Arc::Sdl2::appendTextTextureToPool()
{
    ++ this->_textTextureI;
    if (this->_textTextureI >= this->_pool.textTexture.size()) {
        this->_pool.textTexture.emplace_back();
    }
    // if (!this->_pool.surface.contains(fontPath)) {
    //     SDL_Surface *surface = TTF_OpenFont(fontPath.c_str(), size);
    //     if (!surface) {
    //         throw Arc::DisplayException("Failed to load: " + fontPath);
    //     }
    //     this->_pool.font[fontPath] = surface;
    // }
}

void Arc::Sdl2::displayTile(const Arc::Tile &tile)
{
    appendTextureToPool(tile.imagePath);

    int sizeX = 0;
    int sizeY = 0;
    SDL_QueryTexture(this->_pool.texture.at(tile.imagePath), NULL, NULL, &sizeX, &sizeY);

    SDL_Rect destRect = {tile.pos.x, tile.pos.y, tile.size.x, tile.size.y};
    SDL_RenderCopy(this->_renderer, this->_pool.texture.at(tile.imagePath), NULL, &destRect);
}

void Arc::Sdl2::displayTileSet(const std::vector<Arc::Tile> &tileSet)
{
    for (const Arc::Tile &tileIt : tileSet) {
        this->displayTile(tileIt);
    }
}

void Arc::Sdl2::displayText(const Arc::GameData &gameData)
{
    for (const auto &textIt : gameData.textSet) {
        appendFontToPool(textIt.fontPath);
        appendSurfaceToPool();
        appendTextTextureToPool();

        TTF_SetFontSize(this->_pool.font.at(textIt.fontPath), textIt.size);

        this->_pool.surface[_surfaceI - 1] = TTF_RenderText_Solid(this->_pool.font.at(textIt.fontPath),
            textIt.text.c_str(), this->_colorBind.at(textIt.color)); // ! check error

        SDL_DestroyTexture(this->_pool.textTexture[_textTextureI - 1]);
        this->_pool.textTexture[_textTextureI - 1] =
            SDL_CreateTextureFromSurface(this->_renderer, this->_pool.surface[_surfaceI - 1]); // ! check error

        int sizeX = 0;
        int sizeY = 0;
        SDL_QueryTexture(this->_pool.textTexture[_textTextureI - 1], NULL, NULL, &sizeX, &sizeY);

        SDL_Rect destRect = (SDL_Rect) {.x = textIt.pos.x, .y = textIt.pos.y, .w = sizeX, .h = sizeY};
        SDL_RenderCopy(this->_renderer, this->_pool.textTexture[_textTextureI - 1], NULL, &destRect);
    /*
    // Render text to surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Hello, SDL!", color);
    if (textSurface == nullptr) {
        std::cerr << "TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Create texture from surface
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == nullptr) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
    // Render text texture
    SDL_RenderCopy(renderer, textTexture, NULL, NULL);
    */
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

    this->_ignoreKey = gameData.player.ignoreKey;
}
