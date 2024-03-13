/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
    #define ARCADE_HPP_

    #include <string>

namespace Arc
{
    class Arcade
    {
        public:
            Arcade(int argc, char **argv);
            ~Arcade() = default;

            void lauch();

        private:
            std::string graphicalLib;
    };
}

#endif /* !ARCADE_HPP_ */
