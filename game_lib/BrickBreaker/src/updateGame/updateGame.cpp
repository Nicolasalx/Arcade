/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** updateGame
*/

#include "BrickBreaker.hpp"

void Arc::BrickBreaker::switchDirEvent(const Arc::Event &event)
{
    for (const auto &evt : event.eventType) {
        switch (evt) {
            case Arc::EventType::LEFT:
                moovePlayerLeft();
            break;
            case Arc::EventType::RIGHT:
                moovePlayerRight();
            break;
            default:
            break;
        }
    }
}

const Arc::GameData &Arc::BrickBreaker::update(const Arc::Event &event)
{
    if (this->gameData.player.health == 0) {
        return this->gameData;
    }
    switchDirEvent(event);
    mooveBall();
    playerLooseOneLife();
    checkEndGame();
    return this->gameData;
}
