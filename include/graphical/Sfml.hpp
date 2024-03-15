/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Sfml
*/

#ifndef SFML_HPP_
    #define SFML_HPP_

    #include "ADisplayModule.hpp"
    #include <SFML/Graphics.hpp>

namespace Arc
{
    class Sfml : public ADisplayModule
    {
        public:
            Sfml() = default;
            ~Sfml() = default;
 
            void init();
            Arc::Event getEvent();
            void refresh(const Arc::GameData &gameData);
            void stop();
            const std::string &getName() const;

        private:
            sf::RenderWindow _window;
            sf::Event _event;
            std::vector<sf::Text> _textList;
            std::map<std::string, sf::Font> _fontList;

            std::vector<std::pair<sf::Keyboard::Key, Arc::EventType>> _keybind = {
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
            std::string _name = "Sfml";
    };
}

#endif /* !SFML_HPP_ */
