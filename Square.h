#ifndef SQUARE_H
#define SQUARE_H

#include "Player.h"
#include "GameBoard.h"

#include <string>
#include<set>
#include <iostream>
#include <iomanip>
using namespace std;

class Player;
class GameBoard;
//LEVEL 1 CLASS
class Square {
    public:

        virtual ~Square() = default;

        virtual void initializeBoard() = 0;
        virtual void placeObstacles() = 0;
        virtual void displayBoard() = 0;
        virtual void placeHedgehogs(Player &player, set<int> &numset, int loopCounter, int level) = 0;

        virtual int checkIfTrackNumberIsCorrect(int trackNumber) = 0;
        virtual int checkIfHedgehogPlacementIsCorrect(int placement, string name, set<int> &numset) = 0;
        virtual int movement(int diceValue) = 0;
        virtual void printUserHhgPositions(Player &player) = 0;
        virtual void printPositions(Player &player) = 0;
        virtual int checkTrackEligibility(int &trackNumber, int userChoice, Player player) = 0;
        virtual void playerTryingToMoveHedggehogFromDeepPit(int trackNumber, int &columnNumber) = 0;
        virtual bool checkIfHedgehogCanBeMoved(int trackNumber, int &columnNumber, Player player) = 0;
        virtual void removePlayerFromGame(Player &player, vector<Player> &players, int &indexOfWinner) = 0;
        virtual bool checkPresenceOfHedgeHog(int trackNumber) = 0;

        virtual bool foundNothing(int trackNumber, int &columnNumber, Player &player, int choice) = 0;
        
        virtual bool cellStackIsEmpty(int trackNumber, int &columnNumber) = 0;


        virtual void move(int choice, int trackNumber, int columnNumber, Player &player, vector<Player> &playerVector) = 0;


        virtual void printUserHhgPositionsInTheTrack(Player &player, int trackNumber) = 0;
};

#endif