/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** DisplayException
*/

#ifndef DISPLAYEXCEPTION_HPP_
    #define DISPLAYEXCEPTION_HPP_

    #include <exception>
    #include <string>

namespace Arc
{
    class DisplayException : std::exception
    {
    public:
        explicit DisplayException(const std::string &message) : _message("Display: " + message)
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

#endif /* !DISPLAYEXCEPTION_HPP_ */
