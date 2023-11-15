#include "GameBoard.h"
#include "GameBoard.cpp"
#include "Square.h"
using namespace std;

#include <iostream>

int main() {


    cout << "-----------------------------------------------\n";
    cout << "-----------------------------------------------";
    cout << "\n WELCOME TO IGLE ARGEN\n";
    cout << "-----------------------------------------------\n";
    cout << "-----------------------------------------------\n";

    //CREATION OF GAME BOARD
    GameBoard game(6, 9);

    //Board initialization
    game.initializeBoard();

    // Call this to place obstacles on the board
    game.placeObstacles(); 

    //displaying the board
    cout << "\n  BOARD:\n\n";
    game.displayBoard();

    return 0;
    
}