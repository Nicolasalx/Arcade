/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** getLib
*/

#include "Menu.hpp"

std::string Arc::Menu::getFileName(const std::string &filepath)
{
    std::filesystem::path absoluteFilepath(filepath);
    return absoluteFilepath.filename().string();
}

void Arc::Menu::createTextWithLib(const std::string &name, Pos pos,
    IsSelectable isSelectable)
{
    Arc::Text text;

    text.text = getFileName(name);
    text.color = Arc::Color::WHITE;
    text.fontPath = "fonts/DroidSansMono.ttf";
    text.pos = {pos.x, pos.y};
    text.size = 20;
    this->gameData.textSet.push_back(text);
    if (isSelectable == SELECTABLE) {
        _allTextSelectable.push_back(text);
    }
}

void Arc::Menu::selectTypeLib(const std::string &filename)
{
    Arc::DLLoader<void> libLoader;
    std::string nameLib;
    LibInfo libinfo;

    try {
        libLoader.load(filename);
        nameLib = libLoader.getSymbol<const std::string &>("getName");
    } catch (const std::exception &e) {
        return;
    }
    if (nameLib.find("arcade_G") != std::string::npos) {
        libinfo.name = nameLib;
        libinfo.path = filename;
        this->gameData.lib.game.push_back(libinfo);
    }
    if (nameLib.find("arcade_D") != std::string::npos) {
        libinfo.name = nameLib;
        libinfo.path = filename;
        this->gameData.lib.graphical.push_back(libinfo);
    }
    this->gameData.lib.libState = Arc::LibState::CURRENT_NOT_INIT;
}

void Arc::Menu::getLibFromDirectory()
{
    std::string filename;

    for (const auto &entry : std::filesystem::directory_iterator("./lib/")) {
        filename = "./lib/" + entry.path().filename().string();
        selectTypeLib(filename);
    }
}
