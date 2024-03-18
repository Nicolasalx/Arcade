/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** ncurses_refresh
*/

#include "Ncurses.hpp"
#include <cmath>

void Arc::Ncurses::safeMVPrintW(int x, int y, const std::string &str)
{
    if (COLS > (x + static_cast<int>(str.size())) && LINES > y
        && x >= 0 && y >= 0) {
        mvprintw(y, x, str.c_str());
    }
}

void Arc::Ncurses::displayTileSet(const Arc::GameData &gameData)
{
    for (const auto &currentTile : gameData.tileSet) {
        attron(COLOR_PAIR(this->_colorBind.at(currentTile.color).pair));


        int rectEndX = std::round(((currentTile.size.x + 3.0) / 1920.0) * static_cast<double>(COLS));
        int rectEndY = std::round(((currentTile.size.y + 3.0) / 1080.0) * static_cast<double>(LINES));

        std::string str(rectEndX, currentTile.c);

        for (int i = 0; i < rectEndY; ++i)
        {
            safeMVPrintW((currentTile.pos.x / 1920.0 * COLS),
                (currentTile.pos.y / 1080.0 * LINES) + i, str);
        }
        attroff(COLOR_PAIR(this->_colorBind.at(currentTile.color).pair));
    }
}

void Arc::Ncurses::displayText(const Arc::GameData &gameData)
{
    for (const auto &currentText : gameData.textSet) {
        attron(COLOR_PAIR(this->_colorBind.at(currentText.color).pair));
        safeMVPrintW(currentText.pos.x / 1920.0 * COLS,
            currentText.pos.y / 1080.0 * LINES, currentText.text);
        attroff(COLOR_PAIR(this->_colorBind.at(currentText.color).pair));
    }
}

void Arc::Ncurses::refresh(const Arc::GameData &gameData)
{
    wclear(stdscr);

    displayTileSet(gameData);
    displayText(gameData);

    wrefresh(stdscr);
    this->_ignoreKey = gameData.player.ignoreKey;
}
