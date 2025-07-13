//
// Created by Ido Amit on 13/07/2025.
//
#include "Event.h"
#include "Player.h"
#include "Character.h"

std::string PotionsMerchant::getDescription() const{
    return "PotionsMerchant";
}

std::string PotionsMerchant::apply(Player& player){
    return player.getCharacter().PotionsMerchant(player);
}