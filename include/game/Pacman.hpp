/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_

    #include "AGameModule.hpp"

namespace Arc
{
    class Pacman : public AGameModule
    {
    public:
        Pacman();
        ~Pacman();

        void init(const std::string &lib);
        const Arc::GameData &update(const Arc::Event &event);
        void stop();
        const std::string &getName() const;
    private:
        std::string _name = "arcade_D_pacman";
    };
}

#endif /* !PACMAN_HPP_ */
