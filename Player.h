
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <set>

class Player {
private:
    std::string name;
    std::string color;
    static std::set<std::string> availableColors;
    static std::set<std::string> usedNames; // To keep track of names already used

public:
    Player();
    void enterName(int playerNumber);
    void chooseColor();
    static int enterNumberOfPlayers();
    static void initializeAvailableColors();
    std::string getName() const;
    std::string getColor() const;

    // Additional functionality can be added as needed
};

#endif // PLAYER_H
