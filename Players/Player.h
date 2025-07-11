
#pragma once

#include <memory>
#include <string>

using std::string;
using std::unique_ptr;

class Job;
class Character;

class Player {
private:
    string name; // Max 15 chars and no spaces
    int level;
    int force;
    int currentHealth;
    int maxHealth;
    int coins;
    unique_ptr<Job> job;
    unique_ptr<Character> character;

public:
    Player(string name, unique_ptr<Job> job, unique_ptr<Character> character, int hp = 100, int maxHp = 100, int c = 10):
        name(std::move(name)), level(1), force(5), job(std::move(job)), character(std::move(character)) {
        currentHealth = hp;
        maxHealth = maxHp;
        coins = c;
    }

    /**
     * Gets the description of the player
     *
     * @return - description of the player
    */
    string getDescription() const;

    /**
     * Gets the name of the player
     *
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the current level of the player
     *
     * @return - level of the player
    */
    int getLevel() const;

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Sets the force of the player
    */
    void setForce(int newForce);

    /**
     * Gets the amount of health points the player can has
     *
     * @return - health points of the player
    */
    int getMaxHp() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
    */
    int getHealthPoints() const;

    /**
     * Sets the amount of health points the player currently has
    */
    void setHealthPoints(int newHp);

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
    */
    int getCoins() const;

    /**
     * Sets the amount of coins the player has
     */
    void setCoins(int newCoins);

    /**
        * Gets the job of the player
        *
        * @return - job of the player
       */
    Job& getJob() const;

    /**
        * Gets the character of the player
        *
        * @return - character of the player
       */
    Character& getCharacter() const;
};
