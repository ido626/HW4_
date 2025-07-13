//
// Created by Ido Amit on 13/07/2025.
//
#include "Character.h"
#include "../Utilities.h"

string Responsible::PotionsMerchant(Player& player){
    int hp = player.getHealthPoints();
    const int maxHp = player.getMaxHp();
    int coins = player.getCoins();
    int potionAmount = 0;

    while (coins >= 5 && hp < maxHp) {
        coins -= 5;
        hp = std::min(hp + 10, maxHp);
        potionAmount++;
    }

    player.setCoins(coins);
    player.setHealthPoints(hp);
    return getPotionsPurchaseMessage(player, potionAmount);
}

std::string Responsible::toString() const{
    return "Responsible";
}