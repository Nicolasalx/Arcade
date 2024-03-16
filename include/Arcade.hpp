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
    #include "EventType.hpp"
    #include <set>

namespace Arc
{
    class Arcade
    {
        public:
            Arcade(int argc, const char **argv);
            ~Arcade();

            void launch();
            void loop();

        private:
            void getCurrentLibLoaded();
            bool eventContain(const Arc::Event &eventList, const Arc::EventType &eventType);
            void loadNextDisplay();
            void loadNextGame();

            std::string displayName;
            std::string gameName;
            Arc::IDisplayModule *displayModule = nullptr;
            Arc::IGameModule *gameModule = nullptr;
            Arc::DLLoader<Arc::IDisplayModule> displayLoader;
            Arc::DLLoader<Arc::IGameModule> gameLoader;

            Arc::Lib _lib;
    };
}

#endif /* !ARCADE_HPP_ */
