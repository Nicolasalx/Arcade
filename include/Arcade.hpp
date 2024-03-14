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
    #include "DLLoader.hpp"
    #include <set>

namespace Arc
{
    class Arcade
    {
        public:
            Arcade(int argc, const char **argv);
            ~Arcade() = default;

            void launch();
            void loop(const std::size_t &frameRate);

        private:
            std::string graphicalLib;
            Arc::IDisplayModule *displayModule;
            Arc::IGameModule *gameModule;
            Arc::DLLoader<Arc::IDisplayModule> displayLoader;
            Arc::DLLoader<Arc::IGameModule> gameLoader;
    };
}

#endif /* !ARCADE_HPP_ */
