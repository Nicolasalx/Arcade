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
    #include "Clock.hpp"

namespace Arc
{
    class Arcade
    {
        public:
            Arcade() = default;
            ~Arcade();

            void start(int argc, const char **argv);
            void launch();
            void loop();

        private:
            void getCurrentLibLoaded();
            bool eventContain(const Arc::Event &eventList, const Arc::EventType &eventType);
            void loadNextDisplay();
            void loadNextGame();
            void loadSelectedGame();
            void loadSelectedDisplay();
            void loadMenu();
            void handleCoreEvent(const Arc::Event &eventList);
            void manageLibData(const Arc::Lib &lib);

            std::string displayName;
            std::string gameName;
            Arc::IDisplayModule *displayModule = nullptr;
            Arc::IGameModule *gameModule = nullptr;
            Arc::DLLoader<Arc::IDisplayModule> displayLoader;
            Arc::DLLoader<Arc::IGameModule> gameLoader;
            Arc::Clock _clock;

            Arc::Lib _lib;
    };
}

#endif /* !ARCADE_HPP_ */
