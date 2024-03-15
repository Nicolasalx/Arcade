/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
    #define IDISPLAYMODULE_HPP_

    #include <string>
    #include "Event.hpp"
    #include "GameData.hpp"
    #include <vector>
    #include "LibType.hpp"

namespace Arc
{
    class IDisplayModule
    {
    public:
        virtual ~IDisplayModule() = default;

        virtual void init() = 0;
        virtual Arc::Event getEvent() = 0;
        virtual void refresh(const Arc::GameData &gameData) = 0;
        virtual void stop() = 0;
        virtual const std::string &getName() const = 0;
    };
}

#endif /* !IDISPLAYMODULE_HPP_ */
