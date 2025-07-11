#include "Event.h"
#include "../Players/Player.h"
#include <vector>     // For std::vector
#include <string>     // For std::string
#include <utility>    // For std::move
#include <memory>     // For std::unique_ptr (highly recommended for polymorphic collections)
#include <numeric>    // Not strictly needed for sum loop, but useful for general numeric ops

#pragma once

class Monster : public Event {
protected:
    int m_combatPower;
    int m_loot;
    int m_damage;
    std::string m_name;

public:
    Monster(std::string name, int cp, int l, int d)
        : m_name(std::move(name)), m_combatPower(cp), m_loot(l), m_damage(d) {}


    virtual ~Monster() = default;

    virtual int getCombatPower() const { return m_combatPower; }
    virtual int getLoot() const { return m_loot; }
    virtual int getDamage() const { return m_damage; }
    std::string getName() const { return m_name; }
    virtual void onEncounterEnd();

    void apply(Player& p) override {
        if (p.getJob().CalculateCombatPower - this->getCombatPower() <= 0) {
            p.setHealthPoints(p.getHealthPoints() - this->getDamage()); 
        } else { 
            p.setCoins(p.getCoins() + this->getLoot()); // if players has warrior job, takes damage too
    }


    std::string getDescription() const override {
        return getName() + " (power " + std::to_string(getCombatPower()) + ", loot " +
               std::to_string(getLoot()) + ", damage " + std::to_string(getDamage()) + ")";
    }
}
};

class Snail : public Monster {
public:
    Snail() : Monster("Snail", 5, 2, 10) {}

};

class Slime : public Monster { 
public:
    Slime() : Monster("Slime", 12, 5, 25) {}
};

class Balrog : public Monster {
public:
    Balrog() : Monster("Balrog", 15, 100, 9001) {}

    void onEncounterEnd() override {
        m_combatPower += 2; 
    }
};

class Pack : public Monster {
private:
    std::vector<std::unique_ptr<Monster>> monsters;

public:
    Pack(std::vector<std::unique_ptr<Monster>> m)
        : Monster("Pack", 0, 0, 0), monsters(std::move(m)) {

    }

    // Override getCombatPower to calculate the sum of all members' current combat powers.
    int getCombatPower() const override {
        int totalCombatPower = 0;
        for (const auto& monster_ptr : monsters) {
            totalCombatPower += monster_ptr->getCombatPower();
        }
        return totalCombatPower;
    }

    int getLoot() const override {
        int totalLoot = 0;
        for (const auto& monster_ptr : monsters) {
            totalLoot += monster_ptr->getLoot();
        }
        return totalLoot;
    }

    int getDamage() const override {
        int totalDamage = 0;
        for (const auto& monster_ptr : monsters) {
            totalDamage += monster_ptr->getDamage();
        }
        return totalDamage;
    }

    void apply(Player& p) override {
        Monster::apply(p);

        for (const auto& monster_ptr : monsters) {
            monster_ptr->onEncounterEnd();
        }
    }
    void onEncounterEnd() override {
    }
    std::string getDescription() const override {
        return "Pack of " + std::to_string(monsters.size()) + " members (power " +
               std::to_string(getCombatPower()) + ", loot " + std::to_string(getLoot()) +
               ", damage " + std::to_string(getDamage()) + ")";
    }
};