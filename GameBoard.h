#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <string>
#include <stack>
using namespace std;

#include "Cells.h"
#include "HghPositions.h"

class Square;
class Player;

// This class represents the entire game board, not just a single square.
class GameBoard : public Square
{
public:
    GameBoard();
    GameBoard(int tracks, int columns);
    void initializeBoard();
    void placeObstacles(); // Now public so it can be called from main.
    void displayBoard();
    void placeHedgehogInStartColumn(int track, const std::string &color, int playerCounter, HghPositions hghPositionArray[]);

    Cells **mainBoard;

    void placeHedgehogs(Player &player, set<int> &numset, int loopCounter, int level);

    int checkIfTrackNumberIsCorrect(int trackNumber);
    int checkIfHedgehogPlacementIsCorrect(int placement, string name, set<int> &numset);
    bool checkPresenceOfHedgeHog(int trackNumber);
    void playerTryingToMoveHedggehogFromDeepPit(int trackNumber, int &columnNumber);
    bool cellStackIsEmpty(int trackNumber, int &columnNumber);

    int checkTrackEligibility(int &trackNumber, int userChoice, Player player);
    bool checkIfHedgehogCanBeMoved(int trackNumber, int &columnNumber, Player player);

    void removePlayerFromGame(Player &player, vector<Player> &players, int &indexOfWinner);

    int movement(int diceValue);
    void printUserHhgPositions(Player &player);
    void printPositions(Player &player);

    bool foundNothing(int trackNumber, int &columnNumber, Player &player, int choice);

    void move(int choice, int trackNumber, int columnNumber, Player &player, vector<Player> &playerVector);

    void printUserHhgPositionsInTheTrack(Player & player, int trackNumber);

private:
    int tracks;
    int columns;
    std::vector<std::vector<std::stack<std::string>>> board;
};

#endif
