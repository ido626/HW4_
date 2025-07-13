#pragma once
class Player;
#include <string>


class Job{
public:
    virtual int CalculateCombatPower(const Player& player);
    virtual std::string SolarEclipse(Player& player);
    virtual std::string toString() const = 0;
    virtual ~Job();
};

class Warrior : public Job {
public:
    ~Warrior() override;
    int CalculateCombatPower(const Player& player) override;
    std::string toString() const override;
};

class Magician : public Job{
public:
    ~Magician() override;
    std::string SolarEclipse(Player& player) override;
    std::string toString() const override;
};

class Archer : public Job{
public:
    ~Archer() override = default;
    std::string toString() const override {
        return "Archer";
    }
};