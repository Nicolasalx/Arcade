/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Sdl2_init
*/

#include "Sdl2.hpp"
#include "DisplayException.hpp"

Arc::Sdl2::Sdl2()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw Arc::DisplayException(SDL_GetError());
    }
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    this->_window = SDL_CreateWindow("SDL2 Arcade",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1920, 1080, SDL_WINDOW_SHOWN);
    if (this->_window == nullptr) {
        throw Arc::DisplayException(SDL_GetError());
    }

    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->_renderer == nullptr) {
        throw Arc::DisplayException(SDL_GetError());
    }
}
