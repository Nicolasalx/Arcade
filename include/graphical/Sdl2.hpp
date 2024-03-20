/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Sdl2
*/

#ifndef Sdl2_HPP_
    #define Sdl2_HPP_

    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <SDL2/SDL_ttf.h>
    #include "ADisplayModule.hpp"
    #include "ColorEnum.hpp"
    #include <map>


namespace Arc
{
    struct Pool
    {
        std::vector<SDL_Surface *> surface;
        std::map<std::string, TTF_Font *> font;
        std::vector<SDL_Texture *> textTexture;

        std::map<std::string, SDL_Texture *> texture;
    };

    class Sdl2: public ADisplayModule
    {
    public:
        Sdl2() = default;
        ~Sdl2() = default;

        void init() override;
        Arc::Event getEvent() override;
        void refresh(const Arc::GameData &gameData) override;
        void stop() override;

    private:
        void displayTile(const Arc::Tile &tile);
        void displayTileSet(const std::vector<Arc::Tile> &tileSet);
        void displayText(const Arc::GameData &gameData);
        void displayPlayer(const Arc::GameData &gameData);
        void displayEnemy(const Arc::GameData &gameData);
        void displayItem(const Arc::GameData &gameData);

        void appendTextureToPool(const std::string &texturePath);
        void appendFontToPool(const std::string &fontPath);
        void appendSurfaceToPool();
        void appendTextTextureToPool();
        void createTextTexture(const Arc::Text &textIt);

        void getKeyEvent(Arc::Event &event);
        void putEventInBuffer(Arc::Event &event);
        void putEventInEventList(Arc::Event &event);

        void destroyFont();

        SDL_Window *_window = nullptr;
        SDL_Renderer *_renderer = nullptr;
        SDL_Event _event;
        Pool _pool;

        std::size_t _surfaceI = 0;
        std::size_t _textTextureI = 0;

        std::vector<std::pair<SDL_KeyCode, Arc::EventType>> _keyBind = {
            {SDLK_e, Arc::EventType::EXIT},
            {SDLK_UP, Arc::EventType::UP},
            {SDLK_DOWN, Arc::EventType::DOWN},
            {SDLK_LEFT, Arc::EventType::LEFT},
            {SDLK_RIGHT, Arc::EventType::RIGHT},
            {SDLK_n, Arc::EventType::NEXT_DISPLAY},
            {SDLK_g, Arc::EventType::NEXT_GAME},
            {SDLK_m, Arc::EventType::BACK_MENU},
            {SDLK_r, Arc::EventType::RESTART},
            {SDLK_a, Arc::EventType::INTERACT_1},
            {SDLK_z, Arc::EventType::INTERACT_2},
            {SDLK_RETURN, Arc::EventType::ENTER}
        };
        std::map<Arc::Color, SDL_Color> _colorBind = {
            {Arc::Color::WHITE, {255, 255, 255, 255}},
            {Arc::Color::RED, {255, 0, 0, 255}},
            {Arc::Color::GREEN, {0, 255, 0, 255}},
            {Arc::Color::YELLOW, {255, 255, 0, 255}},
            {Arc::Color::BLUE, {0, 0, 255, 255}},
            {Arc::Color::MAGENTA, {255, 0, 255, 255}},
            {Arc::Color::CYAN, {0, 255, 255, 255}},
            {Arc::Color::BLACK, {0, 0, 0, 255}}
        };
    };
}

#endif /* !Sdl2_HPP_ */
