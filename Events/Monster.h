#pragma once

#include "../Utilities.h"
#include <vector>
#include <utility>


class Monster : public Event {
protected:
    int m_combatPower;
    int m_loot;
    int m_damage;
    std::string m_name;

public:
    Monster(std::string name, int cp, int l, int d)
        : m_combatPower(cp), m_loot(l), m_damage(d), m_name(std::move(name)) {}


    virtual ~Monster() = default;

    virtual int getCombatPower() const { return m_combatPower;}
    virtual int getLoot() const { return m_loot;}
    virtual int getDamage() const { return m_damage;}
    std::string getName() const { return m_name;}
    virtual void onEncounterEnd() { return;}
    virtual int memberCount() const {return 1;}

    string apply(Player& p) override {
        const int damage    = getDamage();
        const int loot      = getLoot();
        const int powerDiff = p.getJob().CalculateCombatPower(p) - getCombatPower();

        //Player loses
        if (powerDiff <= 0) {
            int hpAfter = p.getHealthPoints() - damage;
            p.setHealthPoints(hpAfter > 0 ? hpAfter : 0);
            return getEncounterLostMessage(p, damage);
        }

        //Player wins
        p.setCoins(p.getCoins() + loot);
        p.setLevel(p.getLevel() + 1);

        if (p.getJob().toString() == "Warrior") {
            int hpAfter = p.getHealthPoints() - 10;
            p.setHealthPoints(hpAfter > 0 ? hpAfter : 0);
        }

        return getEncounterWonMessage(p, loot);
    }

    std::string getDescription() const override {
        return getName() + " (power " + std::to_string(getCombatPower()) + ", loot " +
               std::to_string(getLoot()) + ", damage " + std::to_string(getDamage()) + ")";
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

    string apply(Player& p) override {
        string outcome = Monster::apply(p);
        onEncounterEnd();
        return outcome;
    }

    void onEncounterEnd() override {
        m_combatPower += 2;
    }
};

class Pack : public Monster {
private:
    std::vector<std::unique_ptr<Monster>> monsters;

public:
    Pack(std::vector<std::unique_ptr<Monster>> m)
        : Monster("Pack", 0, 0, 0), monsters(std::move(m)) {}

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

    void onEncounterEnd() override {
        for (auto& m : monsters) {
            m->onEncounterEnd();
        }
    }

    string apply(Player& p) override {
        string outcome = Monster::apply(p);
        onEncounterEnd();
        return outcome;
    }

    int memberCount() const override {
        int count = 0;
        for (auto& m : monsters) {
            count += m->memberCount();  // if m is a Pack, calls Pack::memberCount()
        }
        return count;
    }

    std::string getDescription() const override {
        return "Pack of " + std::to_string(memberCount()) + " members (power " +
               std::to_string(getCombatPower()) + ", loot " + std::to_string(getLoot()) +
               ", damage " + std::to_string(getDamage()) + ")";
    }
};