/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sdl2_display_text
*/

#include "Sdl2.hpp"
#include "DisplayException.hpp"

void Arc::Sdl2::createTextTexture(const Arc::Text &textIt)
{
    SDL_FreeSurface(this->_pool.surface[_surfaceI - 1]);
    this->_pool.surface[_surfaceI - 1] = TTF_RenderText_Solid(this->_pool.font.at(textIt.fontPath),
        textIt.text.c_str(), this->_colorBind.at(textIt.color));
    if (this->_pool.surface[_surfaceI - 1] == nullptr) {
        this->stop();
        throw Arc::DisplayException("Fail to render text on surface in SDL2: " + std::string(SDL_GetError()));
    }

    SDL_DestroyTexture(this->_pool.textTexture[_textTextureI - 1]);
    this->_pool.textTexture[_textTextureI - 1] =
        SDL_CreateTextureFromSurface(this->_renderer, this->_pool.surface[_surfaceI - 1]);
    if (this->_pool.textTexture[_textTextureI - 1] == nullptr) {
        this->stop();
        throw Arc::DisplayException("Fail to create a text texture in SDL2: " + std::string(SDL_GetError()));
    }
}

void Arc::Sdl2::displayText(const Arc::GameData &gameData)
{
    int sizeX = 0;
    int sizeY = 0;
    SDL_Rect destRect;

    for (const auto &textIt : gameData.textSet) {
        if (textIt.text.empty()) {
            continue;
        }
        appendFontToPool(textIt.fontPath);
        appendSurfaceToPool();
        appendTextTextureToPool();
        TTF_SetFontSize(this->_pool.font.at(textIt.fontPath), textIt.size);

        this->createTextTexture(textIt);

        SDL_QueryTexture(this->_pool.textTexture[_textTextureI - 1], nullptr, nullptr, &sizeX, &sizeY);

        destRect = {static_cast<int>(textIt.pos.x), static_cast<int>(textIt.pos.y), sizeX, sizeY};
        SDL_RenderCopy(this->_renderer, this->_pool.textTexture[_textTextureI - 1], nullptr, &destRect);
    }
}
