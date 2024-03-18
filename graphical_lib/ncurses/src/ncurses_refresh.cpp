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

void Arc::Ncurses::displayTile(const Arc::Tile &tile)
{
    attron(COLOR_PAIR(this->_colorBind.at(tile.color).pair));

    int rectEndX = std::round(((tile.size.x + 3.0) / 1920.0) * static_cast<double>(COLS));
    int rectEndY = std::round(((tile.size.y + 3.0) / 1080.0) * static_cast<double>(LINES));

    std::string str(rectEndX, tile.c);

    for (int i = 0; i < rectEndY; ++i) {
        safeMVPrintW((tile.pos.x / 1920.0 * COLS),
            (tile.pos.y / 1080.0 * LINES) + i, str);
    }
    attroff(COLOR_PAIR(this->_colorBind.at(tile.color).pair));

}

void Arc::Ncurses::displayTileSet(const std::vector<Arc::Tile> &tileSet)
{
    for (const Arc::Tile &tileIt : tileSet) {
        this->displayTile(tileIt);
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

void Arc::Ncurses::displayPlayer(const Arc::GameData &gameData)
{
    this->displayTileSet(gameData.player.tileSet);
}

void Arc::Ncurses::displayEnemy(const Arc::GameData &gameData)
{
    for (const Arc::Enemy &enemyIt : gameData.enemy) {
        this->displayTileSet(enemyIt.tileSet);
    }
}

void Arc::Ncurses::displayItem(const Arc::GameData &gameData)
{
    for (const Arc::Item &itemIt : gameData.item)
    {
        this->displayTile(itemIt.tile);
    }
}

void Arc::Ncurses::refresh(const Arc::GameData &gameData)
{
    wclear(stdscr);

    displayTileSet(gameData.tileSet);
    displayText(gameData);
    displayPlayer(gameData);
    displayEnemy(gameData);
    displayItem(gameData);

    wrefresh(stdscr);
    this->_ignoreKey = gameData.player.ignoreKey;
}
