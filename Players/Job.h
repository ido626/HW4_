#pragma once
#include "Player.h"

class Job{
public:
    virtual int CalculateCombatPower(const Player& player){
        return player.getForce() + player.getLevel();
    }

    virtual void SolarEclipse(Player& player){
        if(player.getForce() > 0){
            player.setForce(player.getForce()-1);
        }
    }

    virtual std::string toString() const = 0;

    virtual ~Job() = default;
};