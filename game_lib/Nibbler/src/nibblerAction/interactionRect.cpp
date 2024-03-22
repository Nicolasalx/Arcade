/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** interactionRect
*/

#include "Nibbler.hpp"

bool Arc::Nibbler::areaRectsInContact(const Rect &rect1, const Rect &rect2)
{
    double rect1_right = rect1.x + rect1.w;
    double rect1_bottom = rect1.y + rect1.h;
    double rect2_right = rect2.x + rect2.w;
    double rect2_bottom = rect2.y + rect2.h;

    return !(rect1.x > rect2_right || rect2.x > rect1_right || rect1.y > rect2_bottom || rect2.y > rect1_bottom);
}

Rect Arc::Nibbler::calculateRect(const Pos &pos, double size)
{
    Rect rect;

    rect.x = pos.x;
    rect.y = pos.y;
    rect.w = size;
    rect.h = size;
    return rect;
}
