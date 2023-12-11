// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "HghPositions.h"
#include "Square.h"
#include "GameBoard.h"

#include <string>
#include <vector>
#include <set>
using namespace std;

class GameBoard;
class Player {
private:
    string name;
    string color;
    static set<std::string> availableColors;

    //This variable helps in tracking whether the user's hedgehog has moved once or not. Since we don't allow hedgehogs to move sideways in the first step.
    static set<std::string> usedNames; // To keep track of names already used

    int playerWantsToMoveHedgeHogNumber;

public:

    int intialMovement = -1;
    void flush();
    void initializePlayers(vector<Player> &players, int numberOfPlayers);

    void print(vector<Player> &players, int numberOfPlayers);

    // Keep track of isnertion at set in the main.cpp
    int playerCounter = 1;

    // Increment everytime a hedgehog crosses a finish line.
    int finishedHedgehogs;

    //
    int totalHedgeHogs;

    // Hedgehogs that fell into blackhole
    int sleepingHedgehogs;

    HghPositions hghPositionArray[4];

    Player();
    Player(string name, string color);
    void enterName(int playerNumber);
    void chooseColor();
    int enterNumberOfPlayers();
    void initializeAvailableColors();
    string getName() const;
    string getColor() const;
    void placeHedgehogs(GameBoard**board, set<int> &numset, int loopCounter, int level);
    void printUserHhgPositions(GameBoard &board);
    void printUserHhgPositionsInTheTrack(GameBoard &board, int trackNumber);

    int checkIfTrackNumberIsCorrect(int trackNumber);
    int checkIfHedgehogPlacementIsCorrect(int placement, string name, set<int> &numset);

    int movement(GameBoard &board, int diceValue);
    void move(int choice, int trackNumber, int columnNumber,GameBoard &board, vector<Player> &playerVector);

    void printPositions();
};

#endif // PLAYER_H
