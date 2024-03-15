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
    text.color = Arc::Color::RED;
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

void Arc::Menu::init(const std::string &lib)
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

    //_cursorPlace = {
    //    .gameLib = "arcade_menu.so",
    //    .graphicalLib = _allTextSelectable[0].text, // To change
    //    .elemInSelect = _allTextSelectable[0].text
    //};
}

void Arc::Menu::stop()
{
    std::cerr << "Menu is stopped.\n";
}

const Arc::GameData &Arc::Menu::update(const Arc::Event &)
{
    for (const auto &test: _allTextSelectable) {
        std::cout << test.text << "\n";
    }

    
    // ! If Down
    // Change text at index in white
    // _cursorPlace.indexInSelection += 1;
    // Change text at index in yellow

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

    return this->gameData;
}

const std::string &Arc::Menu::getName() const
{
    return this->_name;
}

extern "C"
{
    const std::string &getName()
    {
        static const std::string name = "arcade_G_menu";
        return name;
    }
}
