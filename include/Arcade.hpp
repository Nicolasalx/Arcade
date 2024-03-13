/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
    #define ARCADE_HPP_

    #include <string>
    #include <memory>
    #include "IDisplayModule.hpp"
    #include "IGameModule.hpp"

namespace Arc
{
    class Arcade
    {
        public:
            Arcade(int argc, const char **argv);
            ~Arcade() = default;

            void launch();
            void loop();

        private:
            std::string graphicalLib;
            std::unique_ptr<IDisplayModule> displayModule;
            std::unique_ptr<IGameModule> gameModule;
    };
}

#endif /* !ARCADE_HPP_ */
