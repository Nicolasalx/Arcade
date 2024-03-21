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

namespace Arc
{
    class IDisplayModule
    {
    public:
        virtual ~IDisplayModule() = default;

        virtual Arc::Event getEvent() = 0;
        virtual void refresh(const Arc::GameData &gameData) = 0;
    };
}

#endif /* !IDISPLAYMODULE_HPP_ */
