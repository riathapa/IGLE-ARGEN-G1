// // REMINDER - NEED TO HANDLE THE COLOUR CHOOSING LOOP -

#include "Player.h"
// #include "Player.cpp"
#include <iostream>
#include <algorithm> // Add this line to include the algorithm header
#include <cctype>
#include "GameBoard.h"
#include "GameBoard.cpp"
// #include "Dice.h"
// #include "Dice.cpp"
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

// int Player ::checkIfTrackNumberIsCorrect(int trackNumber)
// {

//     while (true)
//     {
//         std::cout << "\nSPIDERMAN - " << name << ", Please choose the correct track number. [1-6] :: ";
//         cin >> trackNumber;

//         if (trackNumber >= 1 || trackNumber <= 6)
//         {
//             return trackNumber;
//         }
//     }
// }

// int Player ::checkIfHedgehogPlacementIsCorrect(int placement, string name, std::set<int> &numset)
// {

//     while (true)
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//         cout << "\n"
//              << "SPIDERMAN - " << name << ", choose another track. We need to fill the whole column of track in order to start jumping on other hedgehogs :p :: ";
//         cin >> placement;

//         if (numset.find(placement) == numset.end())
//         {
//             return placement;
//         }
//     }
// }

// void Player::placeHedgehogs(GameBoard**board, std::set<int> &numset, int loopCounter, int level)
// {
//     int track;
//     cout << endl;
//     // std::cout << "SPIDERMAN - " << name << ", on which track would you like to place your hedgehog [1-6] :: ";
//     std::cin >> track;

//     // Validate track number
//     if (track < 1 || track > 6)
//     {
//         track = checkIfTrackNumberIsCorrect(track);
//     }

//     // Clear the set if all tracks are chosen
//     // This empties the set, which means a new column is supposed to fill now.

//     if (numset.size() >= 6)
//     {
//         numset.clear();
//         level++;
//     }

//     // Check if track is already chosen
//     if (numset.find(track) != numset.end())
//     {
//         track = checkIfHedgehogPlacementIsCorrect(track, name, numset);
//     }

//     // Attempt to place the hedgehog
//     board.placeHedgehogInStartColumn(track, color, playerCounter, hghPositionArray);
//     numset.insert(track); // Mark this track as chosen

//     vector<string> hoorahs{"Good placement, ", "Nice Choice", "Nice placement", "WOW", "good choice", "OMG! the game will be fun", "Your placement is giving off a vibe of strategy! Let's see what plan you have up your sleeve", "GAME ON", "OHO SCARY"};

//     int slotCall = 0 + (rand() % hoorahs.size());

//     // std::this_thread::sleep_for(std::chrono::seconds(1));
//     // cout << "\nSPIDERMAN - " << hoorahs[slotCall] << " " << name << endl
//     //      << endl;

//     // std::this_thread::sleep_for(std::chrono::seconds(1));
//     if (playerCounter < 4)
//     {
//         playerCounter++;
//     }
// }

// // HANDLES THE MOVEMENT OF THE HEDGEHOG
int Player ::movement(GameBoard &board, int diceValue)
{
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "\nSPIDERMAN - DICE VALUE :: " << diceValue << endl;

    //     std::this_thread::sleep_for(std::chrono::seconds(1));

    // USER INPUT
    int userInput;

    cout << "\nSPIDERMAN - THIS IS AN OPTIONAL STEP. WOULD YOU LIKE TO MOVE YOUR PIECE ON TOP? BEFORE THE COMPULSARY MOVEMENT? PRESS 1 FOR YES. PRESS 2 FOR NO :: ";
    cin >> userInput;

    return userInput;
}

void Player ::move(int choice, int trackNumber, int columnNumber, GameBoard &board, vector<Player> &playerVector)
{
    cout << " Inside move :: " << endl;

    // storing size which will be used later
    int size = board.mainBoard[trackNumber][columnNumber].cellStack.size();

    cout << "\n\nROW NUMBER :: " << trackNumber;
    cout << "\n\nCOLUMN NUMBER :: " << columnNumber;

    // storing value of hedgehog
    string hedgehog = board.mainBoard[trackNumber][columnNumber].cellStack.top();
    cout << "\n\nINCOMING HEDGEHOG :: " << hedgehog << endl;

    string hghNumberInString = hedgehog.substr(hedgehog.size() - 1, 1);
    cout << "\n\nHEDGEHOG NUMBER :: " << hghNumberInString;
    int hedgehogNumber = stoi(hghNumberInString);

    string hghSubString = hedgehog.substr(0, hedgehog.size() - 1);
    cout << "\n\nHEDGEHOG SUBSTRING :: " << hghSubString << endl;

    int row, column;
    if (choice == 1)
    {
        row = trackNumber;
        column = columnNumber + 1;
    }

    if (choice == 2)
    {
        row = trackNumber - 1;
        column = columnNumber;
    }

    if (choice == 3)
    {
        row = trackNumber + 1;
        column = columnNumber;
    }

    if (board.mainBoard[row][column].finishLine)
    {
        for (auto playerIterator : playerVector)
        {
            if (hedgehog.find(playerIterator.getColor()) != -1)
            {
                cout << "\n\nFINISHED HEDGEHOGS BEFORE FINISH LINE :: " << playerIterator.finishedHedgehogs;
                playerIterator.finishedHedgehogs++;
                cout << "\n\nFINISHED HEDGEHOGS AFTER FINISH LINE :: " << playerIterator.finishedHedgehogs;

                // Popping the element since it is going to next cell
                board.mainBoard[trackNumber][columnNumber].cellStack.pop();

                // Removing the last element of array so that after movement, displaying is correct.
                board.mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
                board.mainBoard[trackNumber][columnNumber].elementsCounter--;

                cout << "\nSPIDERMAN - A " << playerIterator.getColor() << " HEDGEHOG JUST CROSSED A FINISH LINE! GOOD JOBBBB!" << endl << endl;

                board.displayBoard();

                return;
            }
        }
    }
    // CHECK IF WE ARE AT A BLACK HOLE OR NOT

    // B L A C K H O L E
    if (board.mainBoard[row][column].cellName.find("BLCKH") != -1)
    {
        cout << "\nSPIDERMAN - OH NO! " << hedgehog << " FELL INTO A BLACKHOLE! AWW YOU POOR THING!" << endl
             << endl;

        // Popping the element since it is going to next cell
        board.mainBoard[trackNumber][columnNumber].cellStack.pop();

        // Removing the last element of array so that after movement, displaying is correct.
        board.mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
        board.mainBoard[trackNumber][columnNumber].elementsCounter--;

        for (int i = 0; i < playerVector.size(); i++)
        {
            if (playerVector[i].getColor().find(hghSubString) != -1)
            {
                // Falling into blackhole means the hedgehog has died
                // So if a hedgehog dies, that means the total numebr of hedgehogs will decrease
                playerVector[i].sleepingHedgehogs++;
                playerVector[i].totalHedgeHogs--;

                if (hedgehog.find("1") != -1)
                {
                    playerVector[i].hghPositionArray[0].accessible = 0;
                    break;
                }
                else if (hedgehog.find("2") != -1)
                {
                    playerVector[i].hghPositionArray[1].accessible = 0;
                    break;
                }
                else if (hedgehog.find("3") != -1)
                {
                    playerVector[i].hghPositionArray[2].accessible = 0;
                    break;
                }
                else if (hedgehog.find("4") != -1)
                {
                    playerVector[i].hghPositionArray[3].accessible = 0;
                    break;
                }
            }
        }
    }

    // W O R M H O L E
    else if (board.mainBoard[row][column].cellName.find("WORMH") != -1)
    {

        cout << "\nSPIDERMAN - " << hedgehog << " FELL INTO A WORMHOLE! BYE BYE!\n";

        srand(time(0));
        int random = 1 + (rand() % 6);

        cout << "\nSPIDERMAN - "
             << "TRANSPORTING " << hedgehog << " TO THE STARTING OF TRACK " << random << endl;

        // Popping the element since it is going to next cell
        board.mainBoard[trackNumber][columnNumber].cellStack.pop();

        // Removing the last element of array so that after movement, displaying is correct.
        board.mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
        board.mainBoard[trackNumber][columnNumber].elementsCounter--;

        // TRANSPORTATION
        board.mainBoard[random][1].cellStack.push(hedgehog);

        // array index starts at 0, but I have made it to be the same as what the user chooses
        board.mainBoard[random][1].elementsDisplayerArray[board.mainBoard[random][1].elementsCounter] = hedgehog;

        // increasing the size of array since the player has moved to this new cell
        board.mainBoard[random][1].elementsCounter++;
    }

    // S H A L L O W - P I T
    else if (board.mainBoard[row][column].cellName.find("SHLWP") != -1)
    {
        // If the stack is empty that means the shallow pit has space for one hedgehog to trap.
        if (board.mainBoard[row][column].cellStack.empty() == 1)
        {

            cout << "\nSPIDERMAN - " << hedgehog << " FELL INTO A SHALLOWPIT";

            cout << "\nSPIDERMAN - AW YOU POOR THING!";

            cout << "\nSPIDERMAN - LOCKING PLAYER IN SHALLOW PIT! I AM SORRY DEAR PLAYER, BUT YOU CAN'T COME OUT UNTIL THE GAME ENDS!";

            // Putting the element in the cell selected by user
            board.mainBoard[row][column].cellStack.push(hedgehog);

            // array index starts at 0;
            board.mainBoard[row][column].elementsDisplayerArray[board.mainBoard[row][column].elementsCounter] = hedgehog;

            // increasing the size of array since the player has moved to this new cell
            board.mainBoard[row][column].elementsCounter++;

            // make accessibility false, because the hedgehog won't be accessible after falling into the shallow pit
            for (auto playerIterator : playerVector)
            {
                if (playerIterator.getName() == hedgehog)
                {
                    playerIterator.hghPositionArray[hedgehogNumber - 1].accessible = false;
                }
            }
        }
        // Popping the element since it is going to next cell
        board.mainBoard[trackNumber][columnNumber].cellStack.pop();

        // Removing the last element of array so that after movement, displaying is correct.
        board.mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
        board.mainBoard[trackNumber][columnNumber].elementsCounter--;

        // After trapping the hedgehog, we want other hedgehogs to skip the shallow pit and go to the next cell, so we'll change the cells
        // But this only happens if and only if the shallow pit already has trapped a hedgehog!
        if (!board.mainBoard[row][column].cellStack.empty() == 1)
        {

            if (choice == 1)
            {
                column = column + 1;
            }

            if (choice == 2)
            {
                row = row - 1;
            }

            if (choice == 3)
            {
                row = row + 1;
            }

            // TRANSPORTATION
            board.mainBoard[row][column].cellStack.push(hedgehog);

            // array index starts at 0;
            board.mainBoard[row][column].elementsDisplayerArray[board.mainBoard[row][column].elementsCounter] = hedgehog;

            // increasing the size of array since the player has moved to this new cell
            board.mainBoard[row][column].elementsCounter++;
        }
    }

    // D E E P - P I T
    else if (board.mainBoard[row][column].cellName.find("DEEPP") != -1)
    {
        cout << "\n\nGoing into deep pit";
        board.mainBoard[row][column].deepPit.push(hedgehog);
        // Increment
        board.mainBoard[row][column].sizeOfDeepPit++;

        board.mainBoard[row][column].elementsDisplayerArray[board.mainBoard[row][column].elementsCounter] = hedgehog;
        board.mainBoard[row][column].elementsCounter++;

        // Popping the element since it is going to next cell
        board.mainBoard[trackNumber][columnNumber].cellStack.pop();
        // Removing the last element of array so that after movement, displaying is correct.
        board.mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
        board.mainBoard[trackNumber][columnNumber].elementsCounter--;

        // make accessibility false, because the hedgehog won't be accessible after falling into the deep pit
        for (auto playerIterator : playerVector)
        {
            cout << "\n\nPLAYER NAME :: " << playerIterator.getName() << endl;
            cout << "\n\nPLAYER COLOR :: " << playerIterator.getColor() << endl;
            cout << "\n\nHEDGEHOG CHECKING :: " << hedgehog << endl;
            if (hedgehog.find(playerIterator.getColor()) != -1)
            {
                cout << "\n\nACCESSIBILITY OF THE HEDGEHOG :: " << hedgehog << " :: " << playerIterator.hghPositionArray[hedgehogNumber - 1].accessible << endl;
                playerIterator.hghPositionArray[hedgehogNumber - 1].accessible = false;
                cout << "\n\nACCESSIBILITY AFTER CHANGING THE STATUS :: " << playerIterator.hghPositionArray[hedgehogNumber - 1].accessible << endl;
            }
        }

        if (board.mainBoard[row][column].sizeOfDeepPit == 3)
        {
            string poppedHgh = board.mainBoard[row][column].deepPit.front();
            cout << "\n\nELEMENT THAT WILL BE POPPED IS :: "
                 << poppedHgh << endl;
            board.mainBoard[row][column].deepPit.pop();

            // Don't forget to decrement
            board.mainBoard[row][column].sizeOfDeepPit--;

            // It's pretty tricky for deep pit.
            // Usually we are using the elementsDisplayerArray of cells class to show the components of a cells
            // I'll explain later
            int j = 0;
            for (int i = 1; i < board.mainBoard[row][column].elementsCounter; i++)
            {
                string temp = board.mainBoard[row][column].elementsDisplayerArray[i];
                board.mainBoard[row][column].elementsDisplayerArray[i] = '\0';
                board.mainBoard[row][column].elementsDisplayerArray[j] = temp;
                j++;
            }

            // Make the hedgehog accessible
            for (auto playerIterator : playerVector)
            {
                if (playerIterator.getColor() == poppedHgh)
                {
                    playerIterator.hghPositionArray[hedgehogNumber - 1].accessible = true;
                }
            }
            // After trapping the hedgehog, we want other hedgehogs to skip the shallow pit and go to the next cell, so we'll change the cells
            // But this only happens if and only if the shallow pit already has trapped a hedgehog!
            if (choice == 1)
            {
                column = column + 1;
            }

            if (choice == 2)
            {
                row = row - 1;
            }

            if (choice == 3)
            {
                row = row + 1;
            }

            // TRANSPORTATION
            board.mainBoard[row][column].cellStack.push(poppedHgh);

            // array index starts at 0;
            board.mainBoard[row][column].elementsDisplayerArray[board.mainBoard[row][column].elementsCounter] = poppedHgh;

            // increasing the size of array since the player has moved to this new cell
            board.mainBoard[row][column].elementsCounter++;
        }
    }
    // CHECK IF THE PLAYER IS TRYNA MOVE THE HEDGEHOG FROM THE DEEP PIT. THAT SHOULD NOT BE ALLOWED.
    else if (board.mainBoard[trackNumber][columnNumber].cellName.find("BLCKH") != -1)
    {
        cout << "\nSPIDERMAN - NU UH DEAR! YOU CAN'T MOVE YOUR HEDGEHOG! IT's TRAPPED IN A DEEP PIT. GOOD HEAVENS, WAIT FOR YOUR LUCK TO TURN AROUND!" << endl;
    }

    // N O R M A L - S T A C K I N G
    else
    {
        // IF IT IS A SHALLOW PIT, WE CAN'T LET THE LAST ELEMENT ESCAPE
        // HAHAHAHHAHAHHA
        // Configure this correctly, the hgh just jumped out
        if (board.mainBoard[trackNumber][columnNumber].cellName.find("SHLWP") != -1)
        {
            if (board.mainBoard[trackNumber][columnNumber].cellStack.empty() != 1 && board.mainBoard[trackNumber][columnNumber].cellStack.size() < 2)
            {

                cout << "\nSPIDERMAN - THE HEDGEHOG CAN'T MOVE BECAUSE IT IS STUCK IN THE SHALLOWPIT! RIP " << hedgehog;
            }

            else
            {
                // Popping the element since it is going to next cell
                board.mainBoard[trackNumber][columnNumber].cellStack.pop();

                // Removing the last element of array so that after movement, displaying is correct.
                board.mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
                board.mainBoard[trackNumber][columnNumber].elementsCounter--;

                // Putting the element in the cell selected by user
                board.mainBoard[row][column].cellStack.push(hedgehog);

                // array index starts at 0;
                board.mainBoard[row][column].elementsDisplayerArray[board.mainBoard[row][column].elementsCounter] = hedgehog;

                // increasing the size of array since the player has moved to this new cell
                board.mainBoard[row][column].elementsCounter++;
            }
        }

        else
        {
            // Popping the element since it is going to next cell
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

            // cout << "\n-----------------------------------------------\n";
            //             std::this_thread::sleep_for(std::chrono::seconds(1));
            //         }

            if (intialMovement == -1)
            {
                intialMovement = 0;
            }
        }
    }
    cout << "\n";

    board.displayBoard();
}

void Player ::printUserHhgPositions(GameBoard &board)
{
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (board.mainBoard[i][j].cellName == "DEEPP")
            {
                cout << "\n\nTHIS IS A DEEP PIT!";
                continue;
            }
            else if (board.mainBoard[i][j].cellName == "SHLWP")
            {
                cout << "\n\nTHIS IS A SHALLOW PIT!";
                continue;
            }

            else if (board.mainBoard[i][j].cellStack.empty() == 0)
            {
                if (board.mainBoard[i][j].cellStack.top().find(color) != -1)
                {
                    if (board.mainBoard[i][j].cellStack.top().find("1") != -1)
                    {
                        hghPositionArray[0].trackNumber = i;
                        cout << "\nValue at 1 :: " << hghPositionArray[0].trackNumber;
                        hghPositionArray[0].columnNumber = j;
                        hghPositionArray[0].accessible = true;
                        continue;
                    }
                    else if (board.mainBoard[i][j].cellStack.top().find("2") != -1)
                    {
                        hghPositionArray[1].trackNumber = i;
                        cout << "\nValue at 2 :: " << hghPositionArray[1].trackNumber;
                        hghPositionArray[1].columnNumber = j;
                        hghPositionArray[1].accessible = true;
                        continue;
                    }
                    else if (board.mainBoard[i][j].cellStack.top().find("3") != -1)
                    {
                        hghPositionArray[2].trackNumber = i;
                        cout << "\nValue at 3 :: " << hghPositionArray[2].trackNumber;
                        hghPositionArray[2].columnNumber = j;
                        hghPositionArray[2].accessible = true;
                        continue;
                    }
                    else if (board.mainBoard[i][j].cellStack.top().find("4") != -1)
                    {
                        hghPositionArray[3].trackNumber = i;
                        cout << "\nValue at 4 :: " << hghPositionArray[3].trackNumber;
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
    int j = -1;

    set<string> setOfTracks;

    for (int i = 0; i < 4; i++)
    {
        // SHOW THEM IN ORDER!! RIGHT NOW THEY ARE DISASSEMBLED
        if (hghPositionArray[i].accessible)
        {
            // Adding plus 1 because we are storing row number in the parameter and for the user track numbers are starting from 1
            setOfTracks.insert("Track " + to_string(hghPositionArray[i].trackNumber) + ", Column " + to_string(hghPositionArray[i].columnNumber));
            j++;
        }
    }

    if (j == -1)
    {
        cout << "\nSPIDERMAN - LOOKS LIKE NO HEDGEHOGS ARE PRESENT FOR THE PLAYER!";
        return;
    }

    cout << "\nSPIDERMAN - Your hedgehogs are available at the following tracks: ";
    cout << endl;
    for (auto setIterator : setOfTracks)
    {
        cout << setIterator << endl;
    }
}

void Player ::printUserHhgPositionsInTheTrack(GameBoard &board, int trackNumber)
{

    int j = 0;
    set<string> setOfTracks;
    for (int i = 1; i < 10; i++)
    {
        if (board.mainBoard[trackNumber][i].cellName == "DEEPP")
        {
            cout << "\n\nTHIS IS A DEEP PIT!";
            continue;
        }
        if (board.mainBoard[trackNumber][i].cellName == "SHLWP")
        {
            cout << "\n\nTHIS IS A SHALLOW PIT!";
            continue;
        }
        if (board.mainBoard[trackNumber][i].cellStack.empty() == 0)
        {
            // Adding plus 1 because we are storing row number in the parameter and for the user track numbers are starting from 1
            setOfTracks.insert("Track " + to_string(trackNumber) + ", Column " + to_string(i));
            j++;
        }
    }

    if(j == 0){
        cout << "\nSPIDERMAN - LOOKS LIKE NO HEDGEHOGS ARE PRESENT FOR THE PLAYER!";
        return;
    }

    cout << "\nSPIDERMAN - Your hedgehogs are available at the following tracks: ";
    cout << endl;
    for (auto setIterator : setOfTracks)
    {
        cout << setIterator << endl;
    }
}