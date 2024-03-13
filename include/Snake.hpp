/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
    #define SNAKE_HPP_

    #include "IDisplayModule.hpp"

class Snake : public IDisplayModule
{
    public:
        Snake();
        ~Snake();

        void init();
        void stop();
        const std::string &getName() const;

    private:
        std::string name = "Snake";
};

#endif /* !SNAKE_HPP_ */
