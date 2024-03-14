/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** FrameRate
*/

#ifndef FRAMERATE_HPP_
    #define FRAMERATE_HPP_

    #include <cstddef>
    #include <chrono>

namespace Arc
{
    class FrameRate
    {
    public:
        static void setFrameRate(std::size_t frameRate);
        static void start();
        static void end();

    private:
        static std::size_t _frameRate;
        static long _frameTime;
        static std::chrono::time_point<std::chrono::steady_clock> _lastClock;
    };
}

#endif /* !FRAMERATE_HPP_ */
