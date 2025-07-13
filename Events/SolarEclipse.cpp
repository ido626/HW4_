//
// Created by Ido Amit on 13/07/2025.
//
#include "Event.h"
#include "Player.h"

std::string SolarEclipse::getDescription() const{
    return "SolarEclipse";
}

std::string SolarEclipse::apply(Player& player){
    return player.getJob().SolarEclipse(player);
}