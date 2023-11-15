#include "Player.h"
#include <iostream>
#include <algorithm> // Add this line to include the algorithm header
#include <cctype> 
using namespace std;

std::set<std::string> Player::availableColors;
std::set<std::string> Player::usedNames; // Initialize the static set for used names

Player::Player() : name(""), color("") {}

// ... Other methods remain unchanged ...


void Player::initializeAvailableColors() {
    // This can be used to reset available colors if necessary
    availableColors = {"Red", "Blue", "Green", "Yellow", "Purple", "Orange"};
}

void Player::enterName(int playerNumber) {
    std::string inputName;
    cout << "\nPLAYER " << playerNumber << " DETAILS";
    std::cout << "\nName: ";
    while (std::cin >> inputName) {
        // Convert input to lowercase for case-insensitive comparison
        std::string lowerName = inputName;
        std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

        // Check if the name has already been used
        if (usedNames.find(lowerName) == usedNames.end()) {
            name = inputName; // Set the unique name
            usedNames.insert(lowerName); // Add it to the set of used names
            break; // Exit the loop as a unique name has been entered
        } else {
            std::cout << "This name is already taken. Please enter a different name: ";
        }
    }
}

// ... Rest of the methods ...

void Player::chooseColor() {
    std::cout << "\nAvailable colors - \n";
    for (const auto& col : availableColors) {
        std::cout << col << " ";
    }
    std::cout << "\n\nChoose your color: ";
    
    while (true) {
        std::cin >> color;
        if (availableColors.find(color) != availableColors.end()) {
            availableColors.erase(color); // Remove chosen color from available colors
            break;
        }
        std::cout << "Color not available or invalid, please choose another color: ";
    }
}

int Player::enterNumberOfPlayers() {
    int numberOfPlayers;
    std::cout << "\nEnter the number of players (2-6): \n";
    while (true) {
        std::cin >> numberOfPlayers;
        if (numberOfPlayers >= 2 && numberOfPlayers <= 6) {
            break;
        }
        std::cout << "Invalid number of players. Please enter a number between 2 and 6: ";
    }
    return numberOfPlayers;
}

std::string Player::getName() const {
    return name;
}

std::string Player::getColor() const {
    return color;
}
