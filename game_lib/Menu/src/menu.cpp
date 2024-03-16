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

void Arc::Menu::createTextWithLib(const std::string &name, Pos pos, enum IsSelectable isSelectable)
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

void Arc::Menu::init()
{
    double posY = 250;

    getLibFromDirectory();
    createTextWithLib(GAME_LIST, (Arc::Pos) {500, 200}, NOT_SELECTABLE);
    createTextWithLib(GRAPHICAL_LIST, (Arc::Pos) {1100, 200}, NOT_SELECTABLE);
    for (const auto &libGame : this->gameData.lib.gamePath) {
        createTextWithLib(libGame, (Arc::Pos) {500, posY += 50}, SELECTABLE);
    }
    posY = 250;
    for (const auto &libGraphical : this->gameData.lib.graphicalPath) {
        createTextWithLib(libGraphical, (Arc::Pos) {1100, posY += 50}, SELECTABLE);
    }
    createTextWithLib(USERNAME, (Arc::Pos) {400, 900}, SELECTABLE);
    createTextWithLib(VALIDATE, (Arc::Pos) {1300, 900}, SELECTABLE);
    if (this->gameData.textSet.size() > 1) {
        this->gameData.textSet[IDX_LIST_START].color = Arc::Color::YELLOW;
    }

    size_t indexText = 0;
    for (const auto &text : this->gameData.textSet) {
        if (getFileName(text.text) == "arcade_menu.so") {
            break;
        }
        ++indexText;
    }

    _cursorPlace = {
        .elemInSelect = 0,
        .gameLib = indexText - IDX_LIST_START, // To change
        .graphicalLib = 25 // To change
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
    size_t indexText = IDX_LIST_START;

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

void Arc::Menu::validateChoice(const std::string &filename, const std::string &bufferEvent)
{
    bool isEnterUsername = false;

    for (const auto &gamePath : this->gameData.lib.gamePath) {
        if (getFileName(gamePath) == filename) {
            _cursorPlace.gameLib = _cursorPlace.elemInSelect;
            this->gameData.lib.currentGame = _cursorPlace.gameLib;
        }
    }
    for (const auto &graphicalPath : this->gameData.lib.graphicalPath) {
        if (getFileName(graphicalPath) == filename) {
            _cursorPlace.graphicalLib = _cursorPlace.elemInSelect;
            this->gameData.lib.currentDisplay = _cursorPlace.graphicalLib - this->gameData.lib.gamePath.size();
        }
    }
    //if (filename == USERNAME) {
    //    if (!isEnterUsername) {
    //        this->gameData.player.ignoreKey = !this->gameData.player.ignoreKey;
    //        
    //    }
    //    return;
    //}

    if (filename == VALIDATE) {
        if (this->gameData.lib.currentGame >= 0 && this->gameData.lib.currentDisplay >= 0) {
            this->gameData.lib.libState = Arc::LibState::NEW_SELECTION;
        }
    }

    // Check if it's username
        // Voir comment on va lire l'input user

    // Check if it's valider
        // Launch le jeu et la lib graphique
}

const Arc::GameData &Arc::Menu::update(const Arc::Event &event)
{
    for (const auto &evt : event.eventType) {
        switch (evt) {
            case Arc::EventType::DOWN:
                selectNextChoice();
            break;
            case Arc::EventType::UP:
                selectPrevChoice();
            break;
            case Arc::EventType::ENTER:
                validateChoice(_allTextSelectable[_cursorPlace.elemInSelect].text, event.buffer);
            break;

            default:
                break;
        }
    }
    if (this->gameData.player.ignoreKey == true) {
        std::cout << "BUFFER: " << event.buffer << "\n";
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
