#include "GameBoard.h"
#include "GameBoard.cpp"
#include "Square.h"
#include "Player.h"
#include "player.cpp"
using namespace std;

#include <iostream>

int main() {


    cout << "\n-----------------------------------------------\n";
    cout << "-----------------------------------------------\n";
    cout << "\n WELCOME TO IGLE ARGEN\n";
    cout << "\n-----------------------------------------------\n";
    cout << "-----------------------------------------------\n";

    Player::initializeAvailableColors();

    // Get the number of players
    int numberOfPlayers = Player::enterNumberOfPlayers(); 

    // Create a vector to hold all players
    std::vector<Player> players;

    // Set up each player
    for (int i = 0; i < numberOfPlayers; ++i) {
        Player currentPlayer;
        currentPlayer.enterName(i + 1);
        currentPlayer.chooseColor();
        players.push_back(currentPlayer);
    }

    cout << "\n-----------------------------------------------\n";
    cout << "-----------------------------------------------\n";

    // Confirm the players' information
    std::cout << "\nThe following players have been entered to the game -\n\n";
    for (const Player& player : players) {
        std::cout << player.getName() 
                  << ", Color: " << player.getColor() << std::endl;
    }

    cout << "\n-----------------------------------------------\n";
    cout << "-----------------------------------------------\n";


    cout << "\nCREATING THE BOARD:\n\n";

    //CREATION OF GAME BOARD
    GameBoard game(6, 9);

    //Board initialization
    game.initializeBoard();

    // Call this to place obstacles on the board
    game.placeObstacles(); 

    //displaying the board
    game.displayBoard();

    cout << "\n-----------------------------------------------\n";
    cout << "-----------------------------------------------\n";

    cout << "\n PLEASE PRESS 1 TO START THE GAME " << endl;

    cout << "\n-----------------------------------------------\n";
    cout << "-----------------------------------------------\n";

    return 0;
    
}