//
// Created by Ido Amit on 13/07/2025.
//
#include "Character.h"
#include "../Utilities.h"

string RiskTaking::PotionsMerchant(Player& player) {
    int currentHp = player.getHealthPoints();
    int maxHp = player.getMaxHp();
    int coins = player.getCoins();
    int potionAmount = 0;

    if (currentHp < 50 && coins >= 5) {
        player.setCoins(player.getCoins() - 5);
        if (currentHp + 10 < maxHp){
            player.setHealthPoints(currentHp + 10);
        }else{
            player.setHealthPoints(maxHp);
        }
    }
    return getPotionsPurchaseMessage(player, potionAmount);
}

std::string RiskTaking::toString() const {
    return "RiskTaking";
}