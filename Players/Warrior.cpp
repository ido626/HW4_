//
// Created by Ido Amit on 13/07/2025.
//

#include "Job.h"
#include "Player.h"
#include "../Utilities.h"

Warrior::~Warrior() = default;

int Warrior::CalculateCombatPower(const Player& player) {
    return player.getForce()*2 + player.getLevel();
}

std::string Warrior::toString() const {
    return "Warrior";
}