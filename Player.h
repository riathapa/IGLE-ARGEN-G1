// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "HghPositions.h"
#include "Square.h"

#include <string>
#include <vector>
#include <set>
using namespace std;

class Player
{
private:
    string name;
    string color;
    static set<std::string> availableColors;
    static set<std::string> usedNames; // To keep track of names already used

    int playerWantsToMoveHedgeHogNumber;

    // vector<int> trackPresenceVector;
    // int sizeOftrackPresenceArray = 0;

public:

    void flush();
    void initializePlayers(vector<Player> &players, int numberOfPlayers);

    void print(vector<Player> &players, int numberOfPlayers);

    // I don't remember
    int playerCounter = 1;
    bool fellIntoBlackHole = false;

    // Increment everytime a hedgehog crosses a finish line.
    int finishedHedgehogs = 0;

    //
    int totalHEdgeHogs = 4;

    // Hedgehogs that fell into blackhole
    int sleepingHedgehogs = 0;

    HghPositions hghPositionArray[4];

    Player();
    Player(string name, string color);
    void enterName(int playerNumber);
    void chooseColor();
    int enterNumberOfPlayers();
    void initializeAvailableColors();
    string getName() const;
    string getColor() const;
    void placeHedgehogs(GameBoard &board, set<int> &numset, int loopCounter, int level);
    // void createTrackPresenceVector();

    int checkIfTrackNumberIsCorrect(int trackNumber);
    int checkIfHedgehogPlacementIsCorrect(int placement, string name, set<int> &numset);
    // void checkUserInputForTrackMovement(int trackNumber);

    int movement(GameBoard &board, int diceValue);
    void userWantsToMove(GameBoard &board);
    void placingOfHedgehog(int trackNumber, int userInput, GameBoard &board);
    int getLocation(int choice, int trackNumber, GameBoard &board, string hedgehogNumber);
    void move(int choice, int trackNumber, int columnNumber,GameBoard &board);

    void printUserHhgPositions(GameBoard &board);
    void printPositions();

    // Additional functionality can be added as needed
};

#endif // PLAYER_H
