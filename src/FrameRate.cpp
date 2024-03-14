/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** FrameRate
*/

#include "FrameRate.hpp"
#include <chrono>
#include <thread>

std::size_t Arc::FrameRate::_frameRate = 30;
long Arc::FrameRate::_frameTime = 1000 / Arc::FrameRate::_frameRate;
std::chrono::time_point<std::chrono::steady_clock> Arc::FrameRate::_lastClock;

void Arc::FrameRate::setFrameRate(std::size_t frameRate)
{
    if (frameRate == 0) {
        frameRate = 30;
    }
    Arc::FrameRate::_frameRate = frameRate;
    Arc::FrameRate::_frameTime = 1000 / frameRate;
}

void Arc::FrameRate::start()
{
    Arc::FrameRate::_lastClock = std::chrono::steady_clock::now();
}

void Arc::FrameRate::end()
{
    auto deltaT = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now() - Arc::FrameRate::_lastClock).count();
    if (deltaT < Arc::FrameRate::_frameTime) {
        std::this_thread::sleep_for(std::chrono::milliseconds(_frameTime - deltaT));
    }
}
