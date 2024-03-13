/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Sfml
*/

#ifndef SFML_HPP_
    #define SFML_HPP_

    #include "IDisplayModule.hpp"

namespace Arc
{
    class Sfml : public IDisplayModule
    {
        public:
            Sfml() = default;
            ~Sfml() = default;
 
            void init();
            std::vector<Arc::Event> getEvent();
            void refresh(const Arc::GameData &gameData);
            void stop();
            const std::string &getName() const;

        protected:
        private:
            std::string name = "Sfml";

        protected:
        private:
    };
}

#endif /* !SFML_HPP_ */
