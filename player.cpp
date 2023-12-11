// // REMINDER - NEED TO HANDLE THE COLOUR CHOOSING LOOP -

#include "Player.h"
#include <iostream>
#include <algorithm> // Add this line to include the algorithm header
#include <cctype>
#include "GameBoard.h"
#include "GameBoard.cpp"
#include <set>
#include <string>
#include <vector>
#include <set>
#include <thread>
using namespace std;

std::set<std::string> Player::availableColors;
std::set<std::string> Player::usedNames; // Initialize the static set for used names

Player ::Player(string name, string color) : name(name), color(color) {}

Player ::Player() : name(""), color("") {}

// // ... Other methods remain unchanged ...

void Player ::initializeAvailableColors()
{
    // This can be used to reset available colors if necessary
    availableColors = {"red", "blue", "green", "yellow", "purple", "orange", "black"};
}

void Player ::flush()
{

    for (int i = 0; i < 4; i++)
    {
        hghPositionArray[i].trackNumber = -1;
        hghPositionArray[i].columnNumber = -1;
        totalHedgeHogs = 4;
        sleepingHedgehogs = 0;
        finishedHedgehogs = 0;
    }
}

void Player ::initializePlayers(vector<Player> &players, int numberOfPlayers)
{
    for (int i = 0; i < numberOfPlayers; ++i)
    {
        Player currentPlayer;
        currentPlayer.enterName(i + 1);
        currentPlayer.chooseColor();
        players.push_back(currentPlayer);
        currentPlayer.flush();
    }
}

void Player::enterName(int playerNumber)
{
    std::string inputName;
    std::cout << "\nEnter the name for player " << playerNumber << ": ";
    while (std::cin >> inputName)
    {
        // Convert input to lowercase for case-insensitive comparison
        std::string lowerName = inputName;
        std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

        // Check if the name has already been used
        if (usedNames.find(lowerName) == usedNames.end())
        {
            name = inputName;            // Set the unique name
            usedNames.insert(lowerName); // Add it to the set of used names
            break;                       // Exit the loop as a unique name has been entered
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "\nDopplegangers are not allowed. Try with a new fancy name. :p";
        }
    }
}

// // ... Rest of the methods ...

void Player::chooseColor()
{
    std::cout << "\nAvailable colors: ";
    for (const auto &col : availableColors)
    {
        std::cout << col << " ";
    }
    std::cout << "\n\nChoose your color: ";

    while (true)
    {
        std::cin >> color;
        if (availableColors.find(color) != availableColors.end())
        {
            availableColors.erase(color); // Remove chosen color from available colors
            break;
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "\nOh Come one, that color is not available. ";
    }
}

int Player::enterNumberOfPlayers()
{
    int numberOfPlayers;
    std::cout << "\nEnter the number of players (2-6): ";
    while (true)
    {
        std::cin >> numberOfPlayers;
        if (numberOfPlayers >= 2 && numberOfPlayers <= 6)
        {
            break;
        }

        std::cout << "\nA game can be played between 2 players or more only, isn't it? If you want to play the game alone, lock yourself in a room!";

        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "\n\nNow enter a number greater than 1 and smaller than 6 ::  ";
    }
    return numberOfPlayers;
}

string Player ::getName() const
{
    return name;
}

string Player ::getColor() const
{
    return color;
}

void Player ::print(vector<Player> &players, int numberOfPlayers)
{
    cout << "\nThe following players have been entered to the game -\n\n";

    for (const Player &player : players)
    {

        std::cout << player.getName()
                  << ", Color: " << player.getColor() << std::endl;
    }
}
