//
// Created by Ido Amit on 13/07/2025.
//
#pragma once
#include <functional>
#include <map>
#include <stdexcept>
#include <sstream>

#include "Player.h"

class Player;

class PlayerFactory {
private:
        std::map<std::string, std::function<std::unique_ptr<Job>()>> jobFactoryMap;
        std::map<std::string, std::function<std::unique_ptr<Character>()>> characterFactoryMap;
public:
        ~PlayerFactory() = default;

        PlayerFactory(){
        jobFactoryMap["Warrior"] = []() { return std::make_unique<Warrior>(); };
        jobFactoryMap["Magician"] = []() { return std::make_unique<Magician>(); };
        jobFactoryMap["Archer"] = []() { return std::make_unique<Archer>(); };

        characterFactoryMap["Responsible"] = []() { return std::make_unique<Responsible>(); };
        characterFactoryMap["RiskTaking"] = []() { return std::make_unique<RiskTaking>(); };
      	}

         std::unique_ptr<Player> createPlayer(const std::string& name, const std::string& job, const std::string& character) const{
            if (!(3 <= name.length() && name.length() <= 15)) {
                throw std::runtime_error("Invalid Players File");
            }

            auto jobIterator = jobFactoryMap.find(job);
            if (jobIterator == jobFactoryMap.end()) {
                throw std::runtime_error("Invalid Players File");
            }
            auto newJob = jobIterator->second();

            auto characterIterator = characterFactoryMap.find(character);
            if (characterIterator == characterFactoryMap.end()) {
                throw std::runtime_error("Invalid Players File");
            }
            auto newCharacter = characterIterator->second();

            auto newPlayer = std::make_unique<Player>(name, std::move(newJob), std::move(newCharacter));
            if (newPlayer->getJob().toString() == "Warrior") {
                newPlayer->setMaxHealthPoints(150);
                newPlayer->setHealthPoints(150);
            }
            else if (newPlayer->getJob().toString() == "Archer") {
                newPlayer->setCoins(newPlayer->getCoins() + 10);
            }

            return newPlayer;
        }


        std::vector<std::unique_ptr<Player>> createPlayerList(std::istream& in) const {
            std::vector<std::unique_ptr<Player>> list;
            while (true) {
                std::string name;
                if (!(in >> name)) {
                    break;
                }

                if (!std::all_of(name.begin(), name.end(),[](unsigned char c){ return std::isalpha(c); })) {
                    throw std::runtime_error("Invalid Players File");
                    }

                std::string job, character;
                if (!(in >> job >> character)) {
                    throw std::runtime_error("Invalid Players File");
                }

                list.push_back(createPlayer(name, job, character));
            }
            return list;
        }
};
