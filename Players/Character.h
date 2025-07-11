#pragma once
#include "Player.h"

class Character{
public:
    virtual void PotionsMerchant(Player& player) = 0;

    virtual std::string toString() const = 0;

    virtual ~Character() = default;
};