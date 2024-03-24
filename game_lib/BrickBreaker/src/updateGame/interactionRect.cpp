/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** interactionRect
*/

#include "BrickBreaker.hpp"

Arc::BrickBreaker::TypeOfContact Arc::BrickBreaker::areaRectsWithContactType(const Rect &rect1, const Rect &rect2)
{
    double rect1_right = rect1.x + rect1.w;
    double rect1_bottom = rect1.y + rect1.h;
    double rect2_right = rect2.x + rect2.w;
    double rect2_bottom = rect2.y + rect2.h;

    bool isLeftOrRight = (rect1.x <= rect2_right && rect2.x <= rect1_right) && (rect1.y < rect2_bottom && rect2.y < rect1_bottom);
    bool isTopOrBottom = (rect1.y <= rect2_bottom && rect2.y <= rect1_bottom) && (rect1.x < rect2_right && rect2.x < rect1_right);

    if (isTopOrBottom && isLeftOrRight) {
        if (rect1.x < X_POS_MAP + SIZE_BORDER + 10 || rect1.x > X_POS_MAP + (SIZE_BORDER * 11)) {
            return HORIZONTAL;
        }
    }

    if (isTopOrBottom) {
        return VERTICAL;
    }

    if (isLeftOrRight) {
        return HORIZONTAL;
    }
    return NONE;
}

Arc::BrickBreaker::TypeOfContactPlayer Arc::BrickBreaker::areaRectsInContact(const Rect &rect1, const Rect &rect2)
{
    double rect1_right = rect1.x + rect1.w;
    double rect1_bottom = rect1.y + rect1.h;
    double rect2_right = rect2.x + rect2.w;
    double rect2_bottom = rect2.y + rect2.h;

    double contactPoint = (rect1_right - rect2.x) / rect2.w;

    if (rect1.x <= rect2_right && rect2.x <= rect1_right && rect1.y <= rect2_bottom && rect2.y <= rect1_bottom) {
        if (contactPoint <= 0.4) {
            return LEFT;
        } else if (contactPoint >= 0.6) {
            return RIGHT;
        } else {
            return MIDDLE;
        }
    }

    return NON;
}

Rect Arc::BrickBreaker::calculateRect(const Pos &pos, double size)
{
    Rect rect;

    rect.x = pos.x;
    rect.y = pos.y;
    rect.w = size;
    rect.h = size;
    return rect;
}
