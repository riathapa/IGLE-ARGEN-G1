#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <vector>
#include <string>


class GameBoard {
public:
    GameBoard(int tracks, int columns);
    void initializeBoard();
    void placeObstacles();
    void displayBoard();

private:
    int tracks;
    int columns;
    std::vector<std::vector<std::string>> board;
};

#endif 