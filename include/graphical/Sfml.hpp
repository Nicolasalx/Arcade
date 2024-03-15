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

            std::string name = "Sfml";
    };
}

#endif /* !SFML_HPP_ */
