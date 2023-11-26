#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <string>
#include<stack>
using namespace std;

#include "Cells.h"
#include "HghPositions.h"

// This class represents the entire game board, not just a single square.
class GameBoard {
public:
    GameBoard(int tracks, int columns);
    void initializeBoard();
    void placeObstacles(); // Now public so it can be called from main.
    void displayBoard();
    void placeHedgehogAt(int track, const std::string& color);
    void dBoard();
    void placeHedgehogInStartColumn(int track, const std::string& color, int playerCounter, HghPositions hghPositionArray[]);

    Cells * * mainBoard;

private:
    int tracks;
    int columns;
    std::vector<std::vector<std::stack<std::string>>> board;
    // vector<vector<stack<std::string>>> mainBoard;
};

#endif // GAMEBOARD_H
