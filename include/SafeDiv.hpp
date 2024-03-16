/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** SafeDiv
*/

#ifndef SAFEDIV_HPP_
    #define SAFEDIV_HPP_

namespace Arc
{
    template<typename T>
    T safeDiv(T a, T b)
    {
        if (b == 0) {
            return 0;
        } else {
            return a / b;
        }
    }

    template<typename T>
    T safeModulo(T a, T b)
    {
        if (b == 0) {
            return 0;
        } else {
            return a % b;
        }
    }
}

#endif /* !SAFEDIV_HPP_ */
