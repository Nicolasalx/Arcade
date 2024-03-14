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

//        Arc::LibType getType() const;
    };
}

#endif /* !ADISPLAYMODULE_HPP_ */
