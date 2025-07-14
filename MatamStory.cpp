

#include "Utilities.h"
#include "MatamStory.h"

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {

    /*===== TODO: Open and read events file =====*/

    eventList = eventFactory.createEventList(eventsStream);
    if (eventList.size() < 2) {
        throw std::runtime_error("Invalid Events File");
    }

    /*==========================================*/


    /*===== TODO: Open and Read players file =====*/

    playerList = playerFactory.createPlayerList(playersStream);
    if (!(2 <= playerList.size() && playerList.size() <= 6)) {
        throw std::runtime_error("Invalid Players File");
    }

    /*============================================*/


    this->m_turnIndex = 1;
}

std::vector<Player*> MatamStory::createLeaderBoard(const std::vector<std::unique_ptr<Player>>& players) {
    std::vector<Player*> leaderBoard;
    for (const auto& player : playerList) {
        leaderBoard.push_back(player.get());
    }

    std::sort(leaderBoard.begin(), leaderBoard.end(), [](const Player* player1, const Player* player2) {
        if (player1->getLevel() == player2->getLevel()) {
            if (player1->getCoins() == player2->getCoins()) {
                return player1->getName() < player2->getName();
            }
            return player1->getCoins() > player2->getCoins();
        }
        return player1->getLevel() > player2->getLevel();
    });

    return leaderBoard;
}

void MatamStory::playTurn(Player& player) {

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Get the next event from the events list */
    int currEventIndex = (m_turnIndex - 1) % eventList.size();
    auto currEvent = std::move(eventList[currEventIndex]);

     /** 2. Print the turn details with "printTurnDetails" */
    printTurnDetails(m_turnIndex, player, *currEvent);

     /** 3. Play the event */
    std::string outcome = currEvent->apply(player);
    eventList[currEventIndex] = std::move(currEvent);

     /** 4. Print the turn outcome with "printTurnOutcome" */
    printTurnOutcome(outcome);
    m_turnIndex++;
}

void MatamStory::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/
    for (auto& player : playerList) {
        if (player->getHealthPoints() > 0) {
            playTurn(*player);
        }
    }
    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/
    std::vector<Player*> leaderBoard = createLeaderBoard(playerList);

    int i = 1;
    for (auto* player : leaderBoard) {
        printLeaderBoardEntry(i, *player);
        i++;
    }

    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    for (const auto& player : playerList) {
        if (player->getLevel() == 10) {
            return true;
        }
    }
    for (const auto& player : playerList) {
        if (player->getHealthPoints() > 0) {
            return false;
        }
    }

    return true;
    /*===================================================*/
}

void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/

    for (int i = 0; i < playerList.size(); i++) {
        printStartPlayerEntry(i + 1, *playerList[i]);
    }

    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/
    std::vector<Player*> leaderBoard = createLeaderBoard(playerList);
    auto possibleWinner = *leaderBoard.begin();
    if (possibleWinner->getLevel() == 10) {
        printWinner(*possibleWinner);
    }
    else {
        printNoWinners();
    }
    /*========================================================================*/
}
