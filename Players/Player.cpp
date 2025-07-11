//
// Created by Ido Amit on 07/07/2025.
//
#include "Player.h"
#include "Job.h"
#include "Character.h"

using std::string;

string Player::getDescription() const {
    return name + ", " + job->toString() + " with " + character->toString() + " character (level " +
           std::to_string(level) + ", force " + std::to_string(force) + ")";
}

string Player::getName() const{
    return name;
}

int Player::getLevel() const{
    return level;
}

int Player::getForce() const{
    return force;
}

void Player::setForce(int newForce) {
    force = newForce;
}

int Player::getMaxHp() const{
    return maxHealth;
}

int Player::getHealthPoints() const{
    return currentHealth;
}

void Player::setHealthPoints(int newHp){
    currentHealth = newHp;
}

int Player::getCoins() const{
    return coins;
}

void Player::setCoins(int newCoins){
    coins = newCoins;
}

Job& Player::getJob() const{
    return *job;
}

Character& Player::getCharacter() const{
    return *character;
}
