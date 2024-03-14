/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** AGameModule
*/

#ifndef AGAMEMODULE_HPP_
    #define AGAMEMODULE_HPP_

    #include "IGameModule.hpp"

namespace Arc
{
    class AGameModule : public Arc::IGameModule
    {
    public:
        virtual ~AGameModule() = default;

        Arc::LibType getType() const;

    protected:
        Arc::GameData gameData;
    };
}

#endif /* !AGAMEMODULE_HPP_ */
