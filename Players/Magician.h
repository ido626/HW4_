#pragma once
#include "Job.h"

class Magician : public Job{
public:
    void SolarEclipse(Player& player) override {
        player.setForce(player.getForce()+1);
    }

    std::string toString() const override {
        return "Magician";
    }
};