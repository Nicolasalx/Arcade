/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** ADisplayModule
*/

#ifndef ADISPLAYMODULE_HPP_
    #define ADISPLAYMODULE_HPP_

    #include "IDisplayModule.hpp"

namespace Arc
{
    class ADisplayModule : public Arc::IDisplayModule
    {
    public:
        virtual ~ADisplayModule() = default;

        virtual void init() = 0;
        virtual std::vector<Arc::Event> getEvent() = 0;
        virtual void refresh(const Arc::GameData &gameData) = 0;
        virtual void stop() = 0;
        virtual const std::string &getName() const = 0;
    };
}

#endif /* !ADISPLAYMODULE_HPP_ */
