
#pragma once

class Job;
class Character;
class Player;
#include <string>

class Event {
public:
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    virtual std::string getDescription() const = 0;

    virtual std::string apply(Player& player) = 0;

    virtual ~Event() = default;
};

class SolarEclipse : public Event {
    std::string getDescription() const override;
    std::string apply(Player& player) override;
};

class PotionsMerchant : public Event {
    std::string getDescription() const override;
    std::string apply(Player& player) override;
};
