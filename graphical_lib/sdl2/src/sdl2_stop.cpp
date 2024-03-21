/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Sdl2_stop
*/

#include "Sdl2.hpp"

void Arc::Sdl2::destroyFont()
{
    for (auto &fontIt : this->_pool.font) {
        if (fontIt.second) {
            TTF_CloseFont(fontIt.second);
        }
    }
    for (auto &surfaceIt : this->_pool.surface) {
        if (surfaceIt) {
            SDL_FreeSurface(surfaceIt);
        }
    }
    for (auto &textTextureIt : this->_pool.textTexture) {
        if (textTextureIt) {
            SDL_DestroyTexture(textTextureIt);
        }
    }
}

void Arc::Sdl2::stop()
{
    for (auto &textureIt : this->_pool.texture) {
        if (textureIt.second) {
            SDL_DestroyTexture(textureIt.second);
        }
    }
    this->destroyFont();
    if (this->_renderer) {
        SDL_DestroyRenderer(this->_renderer);
    }
    if (this->_window) {
        SDL_DestroyWindow(this->_window);
    }
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
