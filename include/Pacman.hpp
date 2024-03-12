/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_

    #include "IDisplayModule.hpp"

class Pacman : public IDisplayModule
{
    public:
        Pacman();
        ~Pacman();

        void init();
        void stop();
        const std::string &getName() const;

    private:
        std::string name = "Pacman";
};

#endif /* !PACMAN_HPP_ */
