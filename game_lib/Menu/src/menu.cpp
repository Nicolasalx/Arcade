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

std::string Arc::Menu::defineNewName(const std::string &name)
{
    const std::string libPath = "./lib/";

    if (name.find(libPath) == 0) {
        return name.substr(libPath.length());
    }
    return name;
}

void Arc::Menu::createTextWithLib(const std::string &name, Pos pos, enum isSelectable_e isSelectable)
{
    Arc::Text text;

    text.text = defineNewName(name);
    text.color = Arc::Color::WHITE;
    text.fontPath = "fonts/DroidSansMono.ttf";
    text.pos = {pos.x, pos.y};
    text.size = 20;
    this->gameData.textSet.push_back(text);
    
    if (isSelectable == SELECTABLE) {
        std::cout << "SELECTABLE -> " << text.text << "\n";
        _allTextSelectable.push_back(std::make_pair(text, isSelectable));
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
    createTextWithLib("Games list:", (Arc::Pos) {500, 200}, isSelectable_e::NOT_SELECTABLE);
    for (const auto &libGame : this->gameData.lib.gamePath) {
        createTextWithLib(libGame, (Arc::Pos) {500, posY += 50}, isSelectable_e::SELECTABLE);
    }
    posY = 250;
    createTextWithLib("Graphicals list:", (Arc::Pos) {1100, 200}, isSelectable_e::NOT_SELECTABLE);
    for (const auto &libGraphical : this->gameData.lib.graphicalPath) {
        createTextWithLib(libGraphical, (Arc::Pos) {1100, posY += 50}, isSelectable_e::SELECTABLE);
    }
    createTextWithLib("Username", (Arc::Pos) {400, 900}, isSelectable_e::SELECTABLE);
    createTextWithLib("Valider", (Arc::Pos) {1300, 900}, isSelectable_e::SELECTABLE);

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
    std::size_t indexText = 0;

    std::cout << "CURSOR ->>>> " << _cursorPlace.elemInSelect << "\n";
    if (_cursorPlace.elemInSelect + 1 > _allTextSelectable.size() - 1) {
        _cursorPlace.elemInSelect = 0;
    } else {
        _cursorPlace.elemInSelect += 1;
    }
    for (const auto &textSelectable : _allTextSelectable) {
        if (textSelectable.second == isSelectable_e::NOT_SELECTABLE) {
            ++indexText;
            continue;
        }
        if (textSelectable.first.text == _allTextSelectable[_cursorPlace.elemInSelect].first.text) {
            this->gameData.textSet[indexText].color = Arc::Color::YELLOW;
        } else {
            this->gameData.textSet[indexText].color = Arc::Color::WHITE;
        }
        ++indexText;
    }
}

void Arc::Menu::selectPrevChoice()
{
    std::size_t indexText = 0;

    std::cout << "CURSOR ->>>> " << _cursorPlace.elemInSelect << "\n";
    if (_cursorPlace.elemInSelect == 0) {
        _cursorPlace.elemInSelect = _allTextSelectable.size() - 1;
    } else {
        _cursorPlace.elemInSelect -= 1;
    }
    for (const auto &textSelectable : _allTextSelectable) {
        if (textSelectable.second == isSelectable_e::NOT_SELECTABLE) {
            ++indexText;
            continue;
        }
        if (textSelectable.first.text == _allTextSelectable[_cursorPlace.elemInSelect].first.text) {
            this->gameData.textSet[indexText].color = Arc::Color::YELLOW;
        } else {
            this->gameData.textSet[indexText].color = Arc::Color::WHITE;
        }
        ++indexText;
    }
}

void Arc::Menu::validateChoice()
{

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
                validateChoice();
            break;

            default:
                break;
        }
    }

    // ! If Up
    // Change text at index in white
    //_cursorPlace.indexInSelection += 1;
    // Change text at index in yellow

    // ! If Enter
    // Check if it's a game lib
        // Le précédent texte est mis en white
        // Le texte à l'index _cursorPlace.indexInSelection devient bleu

    // Check if it's a graphical lib

    // Check if it's username
        // Voir comment on va lire l'input user

    // Check if it's valider
        // Launch le jeu et la lib graphique

    // ! When the user have validated his choice set :
    // this->gameData.lib.currentDisplay = INDEX_OF_THE_DISPLAY;
    // this->gameData.lib.currentGame = INDEX_OF_THE_GAME;
    // this->gameData.lib.libState = Arc::LibState::NEW_SELECTION;
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
