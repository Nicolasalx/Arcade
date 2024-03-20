/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snake
*/

#include "Nibbler.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "Nibbler loaded !\n";
}

extern "C"
{
    Arc::IGameModule *entryPoint(void)
    {
        return new Arc::Nibbler();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Nibbler unloaded !\n";
}

Arc::Nibbler::Nibbler()
{
    std::cout << "Nibbler is class constructed.\n";
}

Arc::Nibbler::~Nibbler()
{
    std::cout << "Nibbler is class destroyed.\n";
}

void Arc::Nibbler::stop()
{
    std::cout << "Nibbler is stopped.\n";
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_nibbler";
        return name;
    }
}
