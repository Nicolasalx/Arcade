/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Sfml
*/

#ifndef SFML_HPP_
    #define SFML_HPP_

    #include "ADisplayModule.hpp"
    #include "ColorEnum.hpp"
    #include <SFML/Graphics.hpp>

namespace Arc
{
    struct Pool
    {
        std::vector<sf::Text> text;
        std::map<std::string, sf::Font> font;

        std::vector<sf::Sprite> sprite;
        std::map<std::string, sf::Texture> texture;
    };

    class Sfml : public ADisplayModule
    {
        public:
            Sfml();
            ~Sfml() override = default;
 
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

            void appendTextToPool();
            void appendFontToPool(const std::string &fontPath);
            void appendSpriteToPool();
            void appendTextureToPool(const std::string &texturePath);

            void putEventInBuffer(Arc::Event &event) const;
            void putEventInEventList(Arc::Event &event);

            sf::RenderWindow _window;
            sf::Event _event;
            Pool _pool;
            std::size_t _spriteI = 0;
            std::size_t _textI = 0;

            std::vector<std::pair<sf::Keyboard::Key, Arc::EventType>> _keyBind = {
                {sf::Keyboard::E, Arc::EventType::EXIT},
                {sf::Keyboard::Up, Arc::EventType::UP},
                {sf::Keyboard::Down, Arc::EventType::DOWN},
                {sf::Keyboard::Left, Arc::EventType::LEFT},
                {sf::Keyboard::Right, Arc::EventType::RIGHT},
                {sf::Keyboard::N, Arc::EventType::NEXT_DISPLAY},
                {sf::Keyboard::G, Arc::EventType::NEXT_GAME},
                {sf::Keyboard::M, Arc::EventType::BACK_MENU},
                {sf::Keyboard::R, Arc::EventType::RESTART},
                {sf::Keyboard::A, Arc::EventType::INTERACT_1},
                {sf::Keyboard::Z, Arc::EventType::INTERACT_2},
                {sf::Keyboard::Enter, Arc::EventType::ENTER}
            };
            std::map<Arc::Color, sf::Color> _colorBind = {
                {Arc::Color::WHITE, sf::Color::White},
                {Arc::Color::RED, sf::Color::Red},
                {Arc::Color::GREEN, sf::Color::Green},
                {Arc::Color::YELLOW, sf::Color::Yellow},
                {Arc::Color::BLUE, sf::Color::Blue},
                {Arc::Color::MAGENTA, sf::Color::Magenta},
                {Arc::Color::CYAN, sf::Color::Cyan},
                {Arc::Color::BLACK, sf::Color::Black}
            };
    };
}

#endif /* !SFML_HPP_ */
