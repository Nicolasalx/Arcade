/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** sdl2_pool
*/

#include "Sdl2.hpp"
#include "DisplayException.hpp"

void Arc::Sdl2::appendFontToPool(const std::string &fontPath)
{
    if (!this->_pool.font.contains(fontPath)) {
        TTF_Font *font = TTF_OpenFont(fontPath.c_str(), 10);
        if (!font) {
            this->stop();
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
}

void Arc::Sdl2::appendTextTextureToPool()
{
    ++ this->_textTextureI;
    if (this->_textTextureI >= this->_pool.textTexture.size()) {
        this->_pool.textTexture.emplace_back();
    }
}
