
#pragma once

#include "../Players/Player.h"

class Event {
public:
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    virtual string getDescription() const = 0;

    virtual void apply(Player& player) = 0;

    virtual ~Event() = default;
};

class SolarEclipse : public Event {
    string getDescription() const override{
        return "SolarEclipse";
    }

    void apply(Player& player) override{
        player.getJob().SolarEclipse(player);
    }
};

class PotionsMerchant : public Event {
    string getDescription() const override{
        return "PotionsMerchant";
    }

    void apply(Player& player) override{
        player.getCharacter().PotionsMerchant(player);
    }
};
