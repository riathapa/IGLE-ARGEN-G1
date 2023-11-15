#include "GameBoard.h"
#include <iostream>

int main() {

    GameBoard game(6, 9);

    //Board initialization
    game.initializeBoard();

    // Call this to place obstacles on the board
    game.placeObstacles(); 

    //displaying the board
    game.displayBoard();

    return 0;
    
}