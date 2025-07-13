//
// Created by Ido Amit on 13/07/2025.
//
#include "../Utilities.h"

Magician::~Magician() = default;

std::string Magician::SolarEclipse(Player& player) {
    player.setForce(player.getForce()+1);
    return getSolarEclipseMessage(player, 1);
}

std::string Magician::toString() const {
    return "Magician";
}