/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** snake
*/

#include <iostream>
#include "Menu.hpp"

__attribute__((constructor)) void init(void)
{
    std::cout << "Menu loaded !\n";
}

extern "C"
{
    Arc::IGameModule *entryPoint(void)
    {
        return new Arc::Menu();
    }
}

__attribute__((destructor)) void destroy(void)
{
    std::cout << "Menu unloaded !\n";
}

Arc::Menu::Menu()
{
    std::cout << "Menu is class constructed.\n";
}

Arc::Menu::~Menu()
{
    std::cout << "Menu is class destroyed.\n";
}

// ! WARNING -> The filepath can be different don't put ./lib/ in DUR
// ../lib/arcade_valo.so

std::string Arc::Menu::getFileName(const std::string &filepath)
{
    std::filesystem::path absoluteFilepath(filepath);
    return absoluteFilepath.filename().string();
}

void Arc::Menu::createTextWithLib(const std::string &name, Pos pos, enum isSelectable_e isSelectable)
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

    try {
        libLoader.load(filename);
        nameLib = libLoader.getName();
    } catch (const std::exception &e) {
        return;
    }
    if (nameLib.find("arcade_G") != std::string::npos) {
        this->gameData.lib.gamePath.push_back(filename);
    }
    if (nameLib.find("arcade_D") != std::string::npos) {
        this->gameData.lib.graphicalPath.push_back(filename);
    }
}

void Arc::Menu::getLibFromDirectory()
{
    std::string filename;

    for (const auto &entry : std::filesystem::directory_iterator("./lib/")) {
        filename = "./lib/" + entry.path().filename().string();
        selectTypeLib(filename);
    }
}

void Arc::Menu::init()
{
    double posY = 250;

    getLibFromDirectory();
    createTextWithLib(GAME_LIST, (Arc::Pos) {500, 200}, isSelectable_e::NOT_SELECTABLE);
    createTextWithLib(GRAPHICAL_LIST, (Arc::Pos) {1100, 200}, isSelectable_e::NOT_SELECTABLE);
    for (const auto &libGame : this->gameData.lib.gamePath) {
        createTextWithLib(libGame, (Arc::Pos) {500, posY += 50}, isSelectable_e::SELECTABLE);
    }
    posY = 250;
    for (const auto &libGraphical : this->gameData.lib.graphicalPath) {
        createTextWithLib(libGraphical, (Arc::Pos) {1100, posY += 50}, isSelectable_e::SELECTABLE);
    }
    createTextWithLib(USERNAME, (Arc::Pos) {400, 900}, isSelectable_e::SELECTABLE);
    createTextWithLib(VALIDATE, (Arc::Pos) {1300, 900}, isSelectable_e::SELECTABLE);
    if (this->gameData.textSet.size() > 1) {
        this->gameData.textSet[2].color = Arc::Color::YELLOW;
    }
    _cursorPlace = {
        .elemInSelect = 0,
        .gameLib = 3, // To change
        .graphicalLib = 4 // To change
    };
}

void Arc::Menu::stop()
{
    std::cerr << "Menu is stopped.\n";
}

void Arc::Menu::selectNextChoice()
{
    if (_cursorPlace.elemInSelect + 1 > _allTextSelectable.size() - 1) {
        _cursorPlace.elemInSelect = 0;
    } else {
        _cursorPlace.elemInSelect += 1;
    }
}

void Arc::Menu::modifyAllTextColor(void)
{
    size_t indexText = 2;

    for (const auto &textSelectable : _allTextSelectable) {
        if (textSelectable.text == _allTextSelectable[_cursorPlace.elemInSelect].text) {
            this->gameData.textSet[indexText].color = Arc::Color::YELLOW;
        } else if (textSelectable.text == _allTextSelectable[_cursorPlace.gameLib].text) {
            this->gameData.textSet[indexText].color = Arc::Color::BLUE;
        } else if (textSelectable.text == _allTextSelectable[_cursorPlace.graphicalLib].text) {
            this->gameData.textSet[indexText].color = Arc::Color::BLUE;
        } else {
            this->gameData.textSet[indexText].color = Arc::Color::WHITE;
        }
        ++indexText;
    }
}

void Arc::Menu::selectPrevChoice(void)
{
    if (_cursorPlace.elemInSelect == 0) {
        _cursorPlace.elemInSelect = _allTextSelectable.size() - 1;
    } else {
        _cursorPlace.elemInSelect -= 1;
    }
}

void Arc::Menu::validateChoice(const std::string &filename)
{
    for (const auto &gamePath : this->gameData.lib.gamePath) {
        if (getFileName(gamePath) == filename) {
            _cursorPlace.gameLib = _cursorPlace.elemInSelect;
        }
    }
    for (const auto &graphicalPath : this->gameData.lib.graphicalPath) {
        if (getFileName(graphicalPath) == filename) {
            _cursorPlace.graphicalLib = _cursorPlace.elemInSelect;
        }
    }
    if (filename == USERNAME) {
    }
    if (filename == VALIDATE) {
    }
    // Check if it's username
        // Voir comment on va lire l'input user

    // Check if it's valider
        // Launch le jeu et la lib graphique
}

const Arc::GameData &Arc::Menu::update(const Arc::Event &event)
{
    for (const auto &event : event.eventType) {
        switch (event) {
            case Arc::EventType::DOWN:
                selectNextChoice();
            break;

            case Arc::EventType::UP:
                selectPrevChoice();
            break;

            case Arc::EventType::ENTER:
                validateChoice(_allTextSelectable[_cursorPlace.elemInSelect].text);
            break;

            default:
                break;
        }
    }
    modifyAllTextColor();
    return this->gameData;
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_menu";
        return name;
    }
}
