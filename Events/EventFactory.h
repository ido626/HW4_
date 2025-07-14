#pragma once

#include "Monster.h"
#include <functional>
#include <map>
#include <iostream>

class EventFactory {
private:
    std::map<std::string, std::function<std::unique_ptr<Event>()>> eventFactoryMap;

public:
    ~EventFactory() = default;
    EventFactory() {
        eventFactoryMap["Snail"] = []() { return std::make_unique<Snail>(); };
        eventFactoryMap["Slime"] = [](){return std::make_unique<Slime>();};
        eventFactoryMap["Balrog"] = []() { return std::make_unique<Balrog>(); };
        eventFactoryMap["SolarEclipse"] = []() { return std::make_unique<SolarEclipse>(); };
        eventFactoryMap["PotionsMerchant"] = []() { return std::make_unique<PotionsMerchant>(); };
    }

    std::unique_ptr<Event> createEvent(const std::string& eventName) const {
        auto it = eventFactoryMap.find(eventName);
        if (it == eventFactoryMap.end()) {
            throw std::runtime_error("Invalid Events File");
        }
        return it->second();
    }

    std::unique_ptr<Event> parseEvent(std::istream& in) const {
        std::string input;
        if (!(in >> input)) {throw std::runtime_error("Invalid Events File");}

        if (input == "Pack") {
            int count;
            if (!(in >> count) || count <= 0)
                throw std::runtime_error("Invalid Events File");

            std::vector<std::unique_ptr<Monster>> packMonsters;
            for (int i = 0; i < count; ++i) {
                auto childEvent = parseEvent(in);
                auto m = dynamic_cast<Monster*>(childEvent.get());
                if (!m) {
                    throw std::runtime_error("Invalid Events File");
                }
                childEvent.release();
                packMonsters.emplace_back(m);
            }

            return std::make_unique<Pack>(std::move(packMonsters));
        }
        else {
            return createEvent(input);
        }
    }

    std::vector<std::unique_ptr<Event>> createEventList(std::istream& eventsStream) const {
        std::vector<std::unique_ptr<Event>> result;
        while (eventsStream >> std::ws && eventsStream.peek() != EOF) {
            result.push_back(parseEvent(eventsStream));
        }
        return result;
    }
};
        //     std::string eventInput;
        //     std::unique_ptr<Event> eventToAdd;
        //     std::vector<std::unique_ptr<Event>> list;
        //
        //     while (eventsStream >> eventInput) {
        //
        //         if (eventInput == "Pack") {
        //             int packSize;
        //             if (!(eventsStream >> packSize) || packSize <= 0) {
        //                 throw std::runtime_error("Invalid Events File");
        //             }
        //
        //             std::vector<std::unique_ptr<Monster>> pack;
        //             for (int i = 0; i < packSize; i++) {
        //                 if (!(eventsStream >> eventInput)) {
        //                     throw std::runtime_error("Invalid Events File");
        //                 }
        //                 auto event = createEvent(eventInput);
        //                 if (auto monster = dynamic_cast<Monster*>(event.get())) {
        //                     pack.push_back(std::make_unique<Monster>(*monster));
        //                 }
        //                 else {
        //                     throw std::runtime_error("Invalid Events File");
        //                 }
        //             }
        //             eventToAdd = std::make_unique<Pack>(pack);
        //         }
        //         else {
        //             eventToAdd = createEvent(eventInput);
        //         }
        //
        //         list.push_back(std::move(eventToAdd));
        //     }
        //
        //     return list;
        // }