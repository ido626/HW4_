#pragma once
#include "Character.h"

class RiskTaking : public Character {
public:
    void PotionsMerchant(Player& player) override {
        int currentHp = player.getHealthPoints();
        int maxHp = player.getMaxHp();
        int coins = player.getCoins();

        if (currentHp < 50 && coins >= 5) {
            player.setCoins(player.getCoins() - 5);
            if (currentHp + 10 < maxHp){
                player.setHealthPoints(currentHp + 10);
            }else{
                player.setHealthPoints(maxHp);
            }
        }
    }
    std::string toString() const override {
        return "RiskTaking";
    }
};