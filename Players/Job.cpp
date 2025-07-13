//
// Created by Ido Amit on 13/07/2025.
//
#include "Job.h"
#include "Player.h"
#include "../Utilities.h"

int Job::CalculateCombatPower(const Player& player){
    return player.getForce() + player.getLevel();
}

std::string Job::SolarEclipse(Player& player){
    if(player.getForce() > 0){
        player.setForce(player.getForce()-1);
    }
    return getSolarEclipseMessage(player, -1);
}

Job::~Job() = default;