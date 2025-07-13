#pragma once
#include <string>

class Player;

class Character{
public:
    virtual std::string PotionsMerchant(Player& player) = 0;

    virtual std::string toString() const = 0;

    virtual ~Character() = default;
};

class Responsible : public Character{
public:
    std::string PotionsMerchant(Player& player) override;
    std::string toString() const override;
};

class RiskTaking : public Character {
public:
    std::string PotionsMerchant(Player& player) override;
    std::string toString() const override;
};