// // REMINDER - NEED TO HANDLE THE COLOUR CHOOSING LOOP -

#include "Player.h"
#include <iostream>
#include <algorithm> // Add this line to include the algorithm header
#include <cctype>
#include "GameBoard.h"
// #include "Dice.h"
// #include "Dice.cpp"
#include <set>
#include <string>
#include <vector>
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
    availableColors = {"red", "blue", "green", "yellow", "purple", "orange"};
}

void Player ::flush()
{

    for (int i = 0; i < 4; i++)
    {
        hghPositionArray[i].trackNumber = -1;
        hghPositionArray[i].columnNumber = -1;
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

        // std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << player.getName()
                  << ", Color: " << player.getColor() << std::endl;
    }
}

int Player ::checkIfTrackNumberIsCorrect(int trackNumber)
{

    while (true)
    {
        std::cout << "\nSPIDERMAN - " << name << ", Please choose the correct track number. [1-6] :: ";
        cin >> trackNumber;

        if (trackNumber >= 1 || trackNumber <= 6)
        {
            return trackNumber;
        }
    }
}

int Player ::checkIfHedgehogPlacementIsCorrect(int placement, string name, std::set<int> &numset)
{

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "\n"
             << "SPIDERMAN - " << name << ", choose another track. We need to fill the whole column of track in order to start jumping on other hedgehogs :p :: ";
        cin >> placement;

        if (numset.find(placement) == numset.end())
        {
            return placement;
        }
    }
}

void Player::placeHedgehogs(GameBoard &board, std::set<int> &numset, int loopCounter, int level)
{
    int track;
    cout << endl;
    // std::cout << "SPIDERMAN - " << name << ", on which track would you like to place your hedgehog [1-6] :: ";
    std::cin >> track;

    // Validate track number
    if (track < 1 || track > 6)
    {
        track = checkIfTrackNumberIsCorrect(track);
    }

    // Clear the set if all tracks are chosen
    // This empties the set, which means a new column is supposed to fill now.

    if (numset.size() >= 6)
    {
        numset.clear();
        level++;
    }

    // Check if track is already chosen
    if (numset.find(track) != numset.end())
    {
        track = checkIfHedgehogPlacementIsCorrect(track, name, numset);
    }

    // Attempt to place the hedgehog
    board.placeHedgehogInStartColumn(track - 1, color, playerCounter, hghPositionArray);
    numset.insert(track); // Mark this track as chosen

    vector<string> hoorahs{"Good placement, ", "Nice Choice", "Nice placement", "WOW", "good choice", "OMG! the game will be fun", "Your placement is giving off a vibe of strategy! Let's see what plan you have up your sleeve", "GAME ON", "OHO SCARY"};

    int slotCall = 0 + (rand() % hoorahs.size());

    // std::this_thread::sleep_for(std::chrono::seconds(1));
    // cout << "\nSPIDERMAN - " << hoorahs[slotCall] << " " << name << endl
    //      << endl;

    // std::this_thread::sleep_for(std::chrono::seconds(1));
    if (playerCounter < 4)
    {
        playerCounter++;
    }
}

// // HANDLES THE MOVEMENT OF THE HEDGEHOG
int Player ::movement(GameBoard &board, int diceValue)
{
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "\nSPIDERMAN - DICE VALUE :: " << diceValue << endl;

    //     std::this_thread::sleep_for(std::chrono::seconds(1));

    // USER INPUT
    int userInput;

    // TRACK NUMBER
    int trackNumber;

    // COLUMN NUMBER
    int columnNumber;
    cout << "\nSPIDERMAN - WOULD YOU LIKE TO MOVE YOUR PIECE ON TOP? BEFORE THE COMPULSARY MOVEMENT? PRESS 1 FOR YES. PRESS 2 FOR NO :: ";
    cin >> userInput;

    return userInput;
    switch (userInput)
    {

    case 1:
        cout << "\nSPIDERMAN - USER CHOSE OPTION " << userInput;
        userWantsToMove(board);

    default:
    }
}
//     //     cout << "\nSPIDERMAN - WHERE WOULD YOU LIKE TO MOVE YOUR PIECE? AHEAD(1)? LEFT(2)? RIGHT?(3) :: ";
//     //     cin >> userInput;

//     //     cout << "\nSPIDERMAN - PLEASE SELECT THE TRACK NUMBER :: ";
//     //     cin >> trackNumber;

//     //     cout << "\nSPIDERMAN - PLEASE SELECT THE COLUMN NUMBER :: ";
//     //     cin >> columnNumber;

//     //     if (userInput == 1)
//     //     {

//     //         if (board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.top().find(name))
//     //         {

//     //             // storing size which will be used later
//     //             int size = board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.size();

//     //             // strogin value of hedgehog
//     //             string hedgehog = board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.top();

//     //             // Popping the element since it is going to next cell
//     //             board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.pop();

//     //             // Removing the last element of array so that after movement, displaying is correct.
//     //             board.mainBoard[trackNumber - 1][columnNumber - 1].elementsDisplayerArray[size - 1] = '\0';
//     //             board.mainBoard[trackNumber - 1][columnNumber - 1].elementsCounter--;

//     //             // Putting the elemtn in the front cell
//     //             board.mainBoard[trackNumber - 1][columnNumber].cellStack.push(hedgehog);

//     //             // array index starts at 0;
//     //             board.mainBoard[trackNumber - 1][columnNumber].elementsDisplayerArray[board.mainBoard[trackNumber - 1][columnNumber].elementsCounter] = hedgehog;

//     //             board.mainBoard[trackNumber - 1][columnNumber].elementsCounter++;

//     //             std::this_thread::sleep_for(std::chrono::seconds(1));

//     //             cout << "\n-----------------------------------------------\n";

//     //             board.displayBoard();

//     //             cout << "\n-----------------------------------------------\n";
//     //             std::this_thread::sleep_for(std::chrono::seconds(1));
//     //         }
//     //     }

//     //     else if (userInput == 2)
//     //     {

//     //         if (board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.top().find(name))
//     //         {

//     //             // storing size which will be used later
//     //             int size = board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.size();

//     //             // strogin value of hedgehog
//     //             string hedgehog = board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.top();
//     //             board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.pop();

//     //             // Removing the last element of array so that after movement, displaying is correct.
//     //             board.mainBoard[trackNumber - 1][columnNumber - 1].elementsDisplayerArray[size - 1] = '\0';
//     //             board.mainBoard[trackNumber - 1][columnNumber - 1].elementsCounter--;

//     //             // Putting the elemtn in the front cell
//     //             board.mainBoard[trackNumber - 2][columnNumber - 1].cellStack.push(hedgehog);

//     //             // array index starts at 0;
//     //             board.mainBoard[trackNumber - 2][columnNumber - 1].elementsDisplayerArray[board.mainBoard[trackNumber - 2][columnNumber - 1].elementsCounter] = hedgehog;

//     //             board.mainBoard[trackNumber - 2][columnNumber - 1].elementsCounter++;

//     //             std::this_thread::sleep_for(std::chrono::seconds(1));

//     //             cout << "\n-----------------------------------------------\n";

//     //             board.displayBoard();

//     //             cout << "\n-----------------------------------------------\n";
//     //             std::this_thread::sleep_for(std::chrono::seconds(1));
//     //         }

//     //         else if (userInput == 3)
//     //         {
//     //             if (board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.top().find(name))
//     //             {

//     //                 // storing size which will be used later
//     //                 int size = board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.size();

//     //                 // strogin value of hedgehog
//     //                 string hedgehog = board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.top();
//     //                 board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.pop();

//     //                 // Removing the last element of array so that after movement, displaying is correct.
//     //                 board.mainBoard[trackNumber - 1][columnNumber - 1].elementsDisplayerArray[size - 1] = '\0';
//     //                 board.mainBoard[trackNumber - 1][columnNumber - 1].elementsCounter--;

//     //                 // Putting the elemtn in the front cell
//     //                 board.mainBoard[trackNumber][columnNumber - 1].cellStack.push(hedgehog);

//     //                 // array index starts at 0;
//     //                 board.mainBoard[trackNumber][columnNumber - 1].elementsDisplayerArray[board.mainBoard[trackNumber - 2][columnNumber].elementsCounter] = hedgehog;

//     //                 board.mainBoard[trackNumber][columnNumber - 1].elementsCounter++;

//     //                 std::this_thread::sleep_for(std::chrono::seconds(1));

//     //                 cout << "\n-----------------------------------------------\n";

//     //                 board.displayBoard();

//     //                 cout << "\n-----------------------------------------------\n";
//     //                 std::this_thread::sleep_for(std::chrono::seconds(1));
//     //             }
//     //         }

//     //     case 2:
//     //         cout << "\nSPIDERMAN - " << name << ", HAS CHOSEN NOT TO MOVE THEIR HEDGEHOG! HMMMM??? STRATEGY PLANNING? LET'S SEE HOW THEY DO!" << endl;

//     //         // default:
//     //     }
//     // }

//     // cout << "\nSPIDERMAN - THE MOVEMENT BY PLAYER HAS BEEN DONE. IT's TIME FOR A COMPULSORY MOVEMENT. " << name << ", WHICH HEDGEHOG ON TRACK " << diceValue << "!!! WOULD, YOU LIKE TO MOVE AHEAD? ENTER THE COLUMN NUMBER :: ";
//     // cin >> columnNumber;

//     // // if (board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.empty())
//     // // {
//     // //     cout << "\nSPIDERMAN - NO ELEMENTS IN THIS SECTION!\n";
//     // // }
//     // // else
//     // // {
//     // // storing size which will be used later
//     // int size = board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.size();
//     // cout << "1";
//     // // strogin value of hedgehog
//     // string hedgehog = board.mainBoard[trackNumber - 1][columnNumber - 1].cellStack.top();
//     // cout << "2";
//     // // Removing the last element of array so that after movement, displaying is correct.
//     // board.mainBoard[trackNumber - 1][columnNumber - 1].elementsDisplayerArray[size - 1] = '\0';
//     // cout << "3";
//     // // Putting the element in the front cell
//     // board.mainBoard[trackNumber - 1][columnNumber].cellStack.push(hedgehog);
//     // cout << "4";
//     // // array index starts at 0;
//     // board.mainBoard[trackNumber - 1][columnNumber].elementsDisplayerArray[board.mainBoard[trackNumber - 1][columnNumber].elementsCounter] = hedgehog;
//     // cout << "5";
//     // board.mainBoard[trackNumber - 1][columnNumber].elementsCounter++;
//     // cout << "6";
//     // // }

//     return;
// }

void Player :: userWantsToMove(GameBoard &board)
{

    int userInput;
    int trackNumber;
    int columnNumber;
    string hedgehogNumber;

    cout << "\n\nSPIDERMAN - WHERE WOULD YOU LIKE TO MOVE YOUR PIECE? AHEAD?(1) LEFT?(2) RIGHT?(3) :: ";
    cin >> userInput;

    // Prints the location where the user's hedgehog can move!
    printUserHhgPositions(board);

}

int Player :: getLocation(int choice, int trackNumber, GameBoard &board, string hedgehogNumber)
{
    cout << " ";
    bool looper = true;

    while (looper)
    {   
        cout << " ";
        for (int i = 0; i < 9; i++)
        {
            cout << " ";
            if (board.mainBoard[trackNumber][i].cellStack.empty() == 0)
            {
                cout << " ";
                if (board.mainBoard[trackNumber][i].cellStack.top().find(hedgehogNumber) != -1)
                {
                    cout << " ";
                    return i;
                }
            }
        }
    }
}

void Player ::move(int choice, int trackNumber, int columnNumber, GameBoard &board)
{
    cout << " Inside move :: " << endl;
    int row, column;
    if (choice == 1)
    {
        row = trackNumber;
        column = columnNumber + 1;
    }

    //             // storing size which will be used later
    int size = board.mainBoard[trackNumber][columnNumber].cellStack.size();

    //             // strogin value of hedgehog
    string hedgehog = board.mainBoard[trackNumber][columnNumber].cellStack.top();

    //             // Popping the element since it is going to next cell
    board.mainBoard[trackNumber][columnNumber].cellStack.pop();

    //             // Removing the last element of array so that after movement, displaying is correct.
    board.mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
    board.mainBoard[trackNumber][columnNumber].elementsCounter--;

    //             // Putting the element in the cell selected by user
    board.mainBoard[row][column].cellStack.push(hedgehog);

    //           // array index starts at 0;
    board.mainBoard[row][column].elementsDisplayerArray[board.mainBoard[row][column].elementsCounter] = hedgehog;

    // increasing the size of array since the player has moved to this new cell
    board.mainBoard[row][column].elementsCounter++;
    cout << "\n";
    //             std::this_thread::sleep_for(std::chrono::seconds(1));

    // cout << "\n-----------------------------------------------\n";

    board.displayBoard();

    // cout << "\n-----------------------------------------------\n";
    //             std::this_thread::sleep_for(std::chrono::seconds(1));
    //         }
}

void Player ::printUserHhgPositions(GameBoard &board)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!(board.mainBoard[i][j].cellStack.empty()))
            {
                if (board.mainBoard[i][j].cellStack.top().find(color) != -1)
                {
                    if (board.mainBoard[i][j].cellStack.top().find("1") != -1)
                    {
                        hghPositionArray[0].trackNumber = i;
                        cout << "\nValue at 1 " << hghPositionArray[0].trackNumber;
                        hghPositionArray[0].columnNumber = j;
                        hghPositionArray[0].accessible = true;
                        continue;
                    }
                    else if (board.mainBoard[i][j].cellStack.top().find("2") != -1)
                    {
                        hghPositionArray[1].trackNumber = i;
                        hghPositionArray[1].columnNumber = j;
                        hghPositionArray[1].accessible = true;
                        continue;
                    }
                    else if (board.mainBoard[i][j].cellStack.top().find("3") != -1)
                    {
                        hghPositionArray[2].trackNumber = i;
                        hghPositionArray[2].columnNumber = j;
                        hghPositionArray[2].accessible = true;
                        continue;
                    }
                    else if (board.mainBoard[i][j].cellStack.top().find("4") != -1)
                    {
                        hghPositionArray[3].trackNumber = i;
                        hghPositionArray[3].columnNumber = j;
                        hghPositionArray[3].accessible = true;
                        continue;
                    }
                }
            }
        }
    }

    printPositions();
}

// USELESS CUS WHAT IF THE PLAYERS IS
void Player ::printPositions()
{
    cout << "\nSPIDERMAN - Your hedgehogs are available at the following tracks: ";
    for (int i = 0; i < 4; i++)
    {
        if (hghPositionArray[i].accessible)
        {
            // Adding plus 1 because we are storing row number in the parameter and for the user track numbers are starting from 1
            cout << "\nTrack " << hghPositionArray[i].trackNumber + 1;
        }
    }
}

// // void Player ::checkUserInputForTrackMovement(int trackNumber)
// // {
// //     bool presence = false;

// //     while (!presence)
// //     {

// //         for (int i = 0; i < sizeOftrackPresenceArray; i++)
// //         {
// //             if (trackPresenceVector[i] == trackNumber)
// //             {
// //                 presence = true;
// //                 cout << "\nSPIDERMAN - NICE SELECTION " << name << "!";

// //                 //deallocating the array, since it's dynamic and resetting the size to 0 for the next loop.
// //                 trackPresenceVector.clear();
// //                 sizeOftrackPresenceArray = 0;
// //                 return;
// //             }
// //         }

// //         cout << "\nSPIDERMAN - " << name << " , please choose the correct track number. Don't be a smarty! Spiderman'e eyes are watching you!!";
// //     }
// // }

//  void Player ::placingOfHedgehog(int trackNumber, int userInput, GameBoard &board)
// {

//     cout << "-";
//     switch (userInput)
//     {

//     // AHEAD MOVEMENT
//     case 1:
//         cout << "-";
//         move(userInput, trackNumber, columnNumber, board);

//     default:
//     }
// }