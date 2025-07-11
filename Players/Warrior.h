#pragma once
#include "Job.h"

class Warrior : public Job {
public:
    int CalculateCombatPower(const Player& player) override {
        return player.getForce()*2 + player.getLevel();
    }

    std::string toString() const override {
        return "Warrior";
    }
};

