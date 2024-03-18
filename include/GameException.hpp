/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** GameException
*/

#ifndef GAMEEXCEPTION_HPP_
    #define GAMEEXCEPTION_HPP_

    #include <stdexcept>

namespace Arc
{
    class GameException : std::exception
    {
    public:
        GameException(const std::string &message) : _message("Game: " + message)
        {
        }

        const char *what() const noexcept override
        {
            return _message.c_str();
        }

    private:
        std::string _message;
    };
}

#endif /* !GAMEEXCEPTION_HPP_ */
