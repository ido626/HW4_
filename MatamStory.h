
#pragma once

#include "Players/PlayerFactory.h"
#include "Events/EventFactory.h"



class MatamStory{
private:
    unsigned int m_turnIndex;
    EventFactory eventFactory;
    PlayerFactory playerFactory;
    std::vector<std::unique_ptr<Event>> eventList;
    std::vector<std::unique_ptr<Player>> playerList;

    std::vector<Player*> createLeaderBoard(const std::vector<std::unique_ptr<Player>>& players);

    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn(Player& player);

    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

public:


    /**
     * Constructor of MatamStory class
     *
     * @param eventsStream - events input stream (file)
     * @param playersStream - players input stream (file)
     *
     * @return - MatamStory object with the given events and players
     *
    */
    MatamStory(std::istream& eventsStream, std::istream& playersStream);

    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();
};
