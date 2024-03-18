/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
    #define CLOCK_HPP_

    #include <chrono>

namespace Arc
{
    class Clock
    {
    public:
        Clock() = default;
        Clock(std::chrono::milliseconds cooldown);
        ~Clock() = default;

        void setCooldown(std::chrono::milliseconds cooldown);
        void start();
        bool isElapsed() const;
        void reset();

    private:
        std::chrono::milliseconds _cooldown;
        std::chrono::steady_clock::time_point _start;
    };
}

#endif /* !CLOCK_HPP_ */
