#pragma once
#include "Character.h"

class Responsible : public Character{
    public:
    void PotionsMerchant(Player& player) override{
        int hp = player.getHealthPoints();
        int maxHp = player.getMaxHealth();
        int coins = player.getCoins();

        while (coins >= 5 && hp < maxHp) {
            coins -= 5;
            hp = std::min(hp + 10, maxHp);
        }

        player.setCoins(coins);
        player.setHealthPoints(hp);
    }

    std::string toString() const override {
        return "Responsible";
    }
};
