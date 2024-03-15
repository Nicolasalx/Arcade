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
            std::vector<Arc::Event> getEvent();
            void refresh(const Arc::GameData &gameData);
            void stop();
            const std::string &getName() const;

        private:
            sf::RenderWindow _window;
            sf::Event _event;
            std::vector<sf::Text> _textList;
            std::map<std::string, sf::Font> _fontList;

            std::vector<std::pair<sf::Keyboard::Key, Arc::Event>> _keybind = {
                {sf::Keyboard::E, Arc::Event::EXIT},
                {sf::Keyboard::Up, Arc::Event::UP},
                {sf::Keyboard::Down, Arc::Event::DOWN},
                {sf::Keyboard::Left, Arc::Event::LEFT},
                {sf::Keyboard::Right, Arc::Event::RIGHT},
                {sf::Keyboard::N, Arc::Event::NEXT_DISPLAY},
                {sf::Keyboard::G, Arc::Event::NEXT_GAME},
                {sf::Keyboard::M, Arc::Event::BACK_MENU},
                {sf::Keyboard::R, Arc::Event::RESTART},
                {sf::Keyboard::A, Arc::Event::INTERACT_1},
                {sf::Keyboard::Z, Arc::Event::INTERACT_2},
                {sf::Keyboard::Enter, Arc::Event::ENTER}
            };
            std::string _name = "Sfml";
    };
}

#endif /* !SFML_HPP_ */
