/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_

    #include "AGameModule.hpp"

namespace Arc
{
    class Snake : public AGameModule
    {
        public:
            Snake();
            ~Snake();

            void init();
            const Arc::GameData &update(const std::vector<Arc::Event> &event);
            void stop();
            const std::string &getName() const;

        private:
            std::string _name = "arcade_D_snake";
    };
}

#endif /* !SNAKE_HPP_ */
