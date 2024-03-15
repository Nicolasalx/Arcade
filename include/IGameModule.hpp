/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
    #define IGAMEMODULE_HPP_

    #include <string>
    #include <vector>
    #include "Event.hpp"
    #include "GameData.hpp"
    #include "LibType.hpp"

namespace Arc
{
    class IGameModule
    {
    public:
        virtual ~IGameModule() = default;

        virtual void init(const std::string &lib) = 0;
        virtual const Arc::GameData &update(const Arc::Event &event) = 0;
        virtual void stop() = 0;
        virtual const std::string &getName() const = 0;
    };
}

#endif /* !IGAMEMODULE_HPP_ */
