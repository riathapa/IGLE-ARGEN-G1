#include "GameBoard.h"
#include "Cells.h"
#include "HghPositions.h"
#include "Cells.cpp"
#include "Player.h"

#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iomanip>
#include <stack>
#include <fstream>
using namespace std;

GameBoard::GameBoard(int tracks, int columns) : tracks(tracks), columns(columns)
{
    tracks = tracks;
    columns = columns;
}

void GameBoard::initializeBoard()
{

    mainBoard = new Cells *[tracks];

    // creating the 2d array
    for (int i = 0; i < columns; i++)
    {
        mainBoard[i] = new Cells[columns];
    }

    // NAMING THE TRACKS
    for (int t = 1; t < tracks; t++)
    {
        mainBoard[t][0].cellName = "TRACK " + to_string(t);
    }

    for (int c = 1; c < columns; c++)
    {
        mainBoard[0][c].cellName = " CN " + to_string(c);
    }

    mainBoard[0][0].cellName = "   .   ";

    for (int t = 1; t < tracks; ++t)
    {

        mainBoard[t][1].cellName = "_____"; // Start squares

        for (int c = 1; c < columns - 1; ++c)
        {

            // Push label to stack for middle squares
            mainBoard[t][c].cellName = "_____";
        }

        // Goal squares
        mainBoard[t][columns - 1].cellName = "| FINISH LINE | "; // Goal squares
    }
}

// OBSTACLES HAVE BEEN HARD CODED
void GameBoard ::placeObstacles()
{
    mainBoard[1][3].cellName = "BLCK";
    mainBoard[2][7].cellName = "WORMH";
    mainBoard[3][5].cellName = "SHLWP";
    mainBoard[4][6].cellName = "SHLWP";
    mainBoard[5][4].cellName = "BLCKH";
    mainBoard[6][8].cellName = "DEEPP";
}

void GameBoard::displayBoard()
{
    ofstream ofObj("output.txt");
    for (int i = 0; i < tracks; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(9);

            if (mainBoard[i][j].cellName.find("| FINISH LINE | ") != -1)
            {
                cout << mainBoard[i][j].cellName << "               ";
                ofObj << mainBoard[i][j].cellName << "               ";
            }

            else if (mainBoard[i][j].cellName.find("SHLWP") != -1)
            {
                cout << setw(10);
                if (mainBoard[i][j].elementsCounter == 0)
                {
                    cout << mainBoard[i][j].cellName << "               ";
                    ofObj << mainBoard[i][j].cellName << "               ";
                    cout << setw(10);
                }

                else
                {
                    cout << mainBoard[i][j].cellName << "+";
                    ofObj << mainBoard[i][j].cellName << "+";
                    mainBoard[i][j].displayElementsOnBoard();
                    mainBoard[i][j].displayElementsOnBoard(ofObj);
                    cout << setw(10);
                }
            }

            else if (mainBoard[i][j].cellName.find("DEEPP") != -1)
            {
                if (mainBoard[i][j].elementsCounter == 0)
                {
                    cout << mainBoard[i][j].cellName << "               ";
                    ofObj << mainBoard[i][j].cellName << "               ";
                    cout << setw(10);
                    ;
                }

                else
                {
                    cout << mainBoard[i][j].cellName << "+";
                    ofObj << mainBoard[i][j].cellName << "+";
                    mainBoard[i][j].displayElementsOnBoard();
                    mainBoard[i][j].displayElementsOnBoard(ofObj);
                    cout << setw(10);
                }
            }
            else if (mainBoard[i][j].elementsCounter == 0)
            {
                cout << mainBoard[i][j].cellName << "               ";
                ofObj << mainBoard[i][j].cellName << "               ";
            }
            else
            {
                mainBoard[i][j].displayElementsOnBoard();
                mainBoard[i][j].displayElementsOnBoard(ofObj);
                cout << setw(10);
            }
        }

        cout << endl
             << endl;
    }
}

void GameBoard::placeHedgehogInStartColumn(int track, const string &color, int playerCounter, HghPositions hghPositionArray[])
{
    // Place hedgehog in the first available spot in the start column
    // This stack maintains the elements
    mainBoard[track][1].cellStack.push(color + to_string(playerCounter));

    // This array is uses to show the players the placement of all their hedgehogs and in order, with the right side representing the top of the stack
    mainBoard[track][1].elementsDisplayerArray[mainBoard[track][1].elementsCounter] = color + to_string(playerCounter);

    mainBoard[track][1].elementsCounter++;

    // Tracking the position of the hedgehog also and saving it in a dynamic array made of class HghPositions. Declared in Player class.
    hghPositionArray[playerCounter - 1].trackNumber = track;
    hghPositionArray[playerCounter - 1].columnNumber = 1;

    // Adding cout because the program starts running out of memory idk why
    cout << " " << endl;
}

bool GameBoard ::checkPresenceOfHedgeHog(int trackNumber)
{
    for (int i = 1; i < columns; i++)
    {
        if (mainBoard[trackNumber][i].cellStack.empty() != 1)
        {
            return true;
        }
    }
    return false;
}

int GameBoard ::checkTrackEligibility(int &trackNumber, int userChoice, Player player)
{
    if (userChoice == 1)
    {
        if (trackNumber < 1 || trackNumber > 7)
        {
            bool y = true;

            while (y)
            {
                cout << "\nSPIDERMAN - DON'T BE SMART! ENTER CORRECT TRACK NUMBER :: ";
                cin >> trackNumber;

                if (trackNumber > 0 || trackNumber < 7)
                {
                    return true;
                }
            }
        }
    }

    if (userChoice == 2)
    {
        if (trackNumber - 2 < 0)
        {

            bool l = true;
            while (l)
            {
                cout << "\nSPIDERMAN - FUNNY OF YOU TO MOVE ANY HEDGEHOG OUT OF THE BOARD " << player.getName() << ". CHOOSE A PROPER TRACK. YOU CAN'T MOVE TO LEFT! :: ";

                cin >> trackNumber;

                if (-1 < trackNumber - 2)
                {
                    l = false;
                    return true;
                }
                cout << "\nL :: " << l << endl;
                cout << "\nSKIPPED!" << endl;
            }
        }
    }

    if (userChoice == 3)
    {
        if (trackNumber > 5)
        {

            bool l = true;
            while (l)
            {
                cout << "\nSPIDERMAN - FUNNY OF YOU TO MOVE ANY HEDGEHOG OUT OF THE BOARD " << player.getName() << ". CHOOSE A PROPER TRACK. YOU CAN'T MOVE TO RIGHT! :: ";

                cin >> trackNumber;

                if (trackNumber < 6)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool GameBoard ::checkIfHedgehogCanBeMoved(int trackNumber, int &columnNumber, Player player)
{
    bool k = true;
    while (k)
    {

        cout << "\nSPIDERMAN - LOOKS LIKE THE COLUMN NUMBER YOU CHOSE IS NOT CORRECT. PLEASE RECHECK THE COLUMN NUMBER AND ENTER IT :: ";
        cin >> columnNumber;

        if (mainBoard[trackNumber][columnNumber].cellStack.empty() == 1 || mainBoard[trackNumber][columnNumber].cellStack.top().find(player.getColor()) != -1)
        {
            return true;
        }
    }

    return false;
}

bool GameBoard ::foundNothing(int trackNumber, int &columnNumber, Player &player, int choice)
{
    if (choice == 1)
    {
        if (mainBoard[trackNumber][columnNumber].cellStack.empty() == 1 || mainBoard[trackNumber][columnNumber].cellStack.top().find(player.getColor()) == -1)
        {
            checkIfHedgehogCanBeMoved(trackNumber, columnNumber, player);
        }
    }

    if (choice == 2)
    {
        if (mainBoard[trackNumber][columnNumber].cellStack.empty() == 1)
        {
            cellStackIsEmpty(trackNumber, columnNumber);
        }
    }
    return false;
}

void GameBoard ::removePlayerFromGame(Player &player, vector<Player> &players, int &indexOfWinner)
{
    cout << "\nSPIDERMAN - " << player.getName() << " BOOO! YOU ARE OUT OF THE GAME! BETTER LUCK NEXT TIME BUDDY!" << endl;
    for (int i = 0; i < players.size(); i++)
    {
        if (players[i].getName().find(player.getName()) != -1)
        {
            players.erase(players.begin() + i);
            indexOfWinner = i;
        }
    }
}

void GameBoard ::playerTryingToMoveHedggehogFromDeepPit(int trackNumber, int &columnNumber)
{
    if (mainBoard[trackNumber][columnNumber].cellName == "DEEPP")
    {
        bool l = true;
        while (l)
        {
            cout << "\nSPIDERMAN - NU UH DEAR! YOU CAN'T MOVE YOUR HEDGEHOG! IT's TRAPPED IN A DEEP PIT. GOOD HEAVENS, WAIT FOR YOUR LUCK TO TURN AROUND!";
            cout << "\n\nSPIDERMAN - CHOOSE FROM THE COLUMNS MENTIONED ABOVE :: ";
            cin >> columnNumber;

            if (mainBoard[trackNumber][columnNumber].cellName != "DEEPP")
            {
                break;
            }
        }
    }
}

bool GameBoard ::cellStackIsEmpty(int trackNumber, int &columnNumber)
{
    bool k = true;
    while (k)
    {
        cout << "\nSPIDERMAN - LOOKS LIKE THE COLUMN NUMBER YOU CHOSE DOES NOT HAVE ANY HEDGEHOG THAT CAN BE MOVED. PLEASE RECHECK THE COLUMN NUMBER AND ENTER IT :: ";
        cin >> columnNumber;

        if (mainBoard[trackNumber][columnNumber].cellStack.empty() != 1)
        {
            return true;
        }
    }

    return false;
}

int GameBoard ::checkIfTrackNumberIsCorrect(int trackNumber)
{

    while (true)
    {
        cout << "\nSPIDERMAN - "
             << "PLEASE CHOOSE THE CORRECT TRACK NUMBER. [1-6] :: ";
        cin >> trackNumber;

        if (trackNumber >= 1 || trackNumber <= 6)
        {
            return trackNumber;
        }
    }
}

int GameBoard ::checkIfHedgehogPlacementIsCorrect(int placement, string name, std::set<int> &numset)
{

    while (true)
    {
        cout << "\n"
             << "SPIDERMAN - " << name << ", CHOOSE ANOTHER TRACK BECAUSE WE CAN ONLY SIT ON OTHER HEDGEHOGS ONCE THE COLUMN IS FILLED:: ";
        cin >> placement;

        if (numset.find(placement) == numset.end())
        {
            return placement;
        }
    }
}
void GameBoard::placeHedgehogs(Player &player, set<int> &numset, int loopCounter, int level)
{
    int track;
    cout << endl;
    cout << "\n\nSPIDERMAN - " << player.getName() << " ON WHICH TRACK WOULD YOU LIKE TO PLACE YOUR HEDGEHOG :: ";
    cin >> track;

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
        track = checkIfHedgehogPlacementIsCorrect(track, player.getName(), numset);
    }

    // Attempt to place the hedgehog
    placeHedgehogInStartColumn(track, player.getColor(), player.playerCounter, player.hghPositionArray);
    numset.insert(track); // Mark this track as chosen

    vector<string> hoorahs{"Good placement, ", "Nice Choice", "Nice placement", "WOW", "good choice", "OMG! the game will be fun", "Your placement is giving off a vibe of strategy! Let's see what plan you have up your sleeve", "GAME ON", "OHO SCARY"};

    int slotCall = 0 + (rand() % hoorahs.size());

    cout << "\nSPIDERMAN - " << hoorahs[slotCall] << " " << player.getName() << endl
         << endl;

    if (player.playerCounter < 4)
    {
        player.playerCounter++;
    }
}

// // HANDLES THE MOVEMENT OF THE HEDGEHOG
int GameBoard ::movement(int diceValue)
{
    cout << "\nSPIDERMAN - DICE VALUE :: " << diceValue << endl;

    // USER INPUT
    int userInput;

    cout << "\nSPIDERMAN - THIS IS AN OPTIONAL STEP. WOULD YOU LIKE TO MOVE YOUR PIECE ON TOP? BEFORE THE COMPULSARY MOVEMENT? PRESS 1 FOR YES. PRESS 2 FOR NO :: ";
    cin >> userInput;

    return userInput;
}

void GameBoard ::printUserHhgPositions(Player &player)
{
    for (int i = 1; i < 7; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (mainBoard[i][j].cellName == "DEEPP")
            {
                continue;
            }
            else if (mainBoard[i][j].cellName == "SHLWP")
            {
                continue;
            }

            else if (mainBoard[i][j].cellStack.empty() == 0)
            {
                if (mainBoard[i][j].cellStack.top().find(player.getColor()) != -1)
                {
                    if (mainBoard[i][j].cellStack.top().find("1") != -1)
                    {
                        player.hghPositionArray[0].trackNumber = i;
                        player.hghPositionArray[0].columnNumber = j;
                        player.hghPositionArray[0].accessible = true;
                        continue;
                    }
                    else if (mainBoard[i][j].cellStack.top().find("2") != -1)
                    {
                        player.hghPositionArray[1].trackNumber = i;
                        player.hghPositionArray[1].columnNumber = j;
                        player.hghPositionArray[1].accessible = true;
                        continue;
                    }
                    else if (mainBoard[i][j].cellStack.top().find("3") != -1)
                    {
                        player.hghPositionArray[2].trackNumber = i;
                        player.hghPositionArray[2].columnNumber = j;
                        player.hghPositionArray[2].accessible = true;
                        continue;
                    }
                    else if (mainBoard[i][j].cellStack.top().find("4") != -1)
                    {
                        player.hghPositionArray[3].trackNumber = i;
                        player.hghPositionArray[3].columnNumber = j;
                        player.hghPositionArray[3].accessible = true;
                        continue;
                    }
                }
            }
        }
    }

    printPositions(player);
}

// USELESS CUS WHAT IF THE PLAYERS IS
void GameBoard ::printPositions(Player &player)
{
    int j = -1;

    set<string> setOfTracks;

    for (int i = 0; i < 4; i++)
    {
        // SHOW THEM IN ORDER!! RIGHT NOW THEY ARE DISASSEMBLED
        if (player.hghPositionArray[i].accessible)
        {
            // Adding plus 1 because we are storing row number in the parameter and for the user track numbers are starting from 1
            setOfTracks.insert("TRACK " + to_string(player.hghPositionArray[i].trackNumber) + ", COLUMN " + to_string(player.hghPositionArray[i].columnNumber));
            j++;
        }
    }

    if (j == -1)
    {
        cout << "\nSPIDERMAN - LOOKS LIKE NO HEDGEHOGS ARE PRESENT TO MOVE " << endl;
        return;
    }

    cout << "\nSPIDERMAN - HEDGEHOGS READY TO MOVE ARE ON THESE TRACKS :: ";
    cout << endl;
    for (auto setIterator : setOfTracks)
    {
        cout << setIterator << endl;
    }
}

void GameBoard ::move(int choice, int trackNumber, int columnNumber, Player &player, vector<Player> &playerVector)
{
    // storing size which will be used later
    int size = mainBoard[trackNumber][columnNumber].cellStack.size();

    // storing value of hedgehog
    string hedgehog = mainBoard[trackNumber][columnNumber].cellStack.top();

    string hghNumberInString = hedgehog.substr(hedgehog.size() - 1, 1);
    int hedgehogNumber = stoi(hghNumberInString);

    string hghSubString = hedgehog.substr(0, hedgehog.size() - 1);

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

    if (mainBoard[row][column].cellName == "| FINISH LINE | ")
    {
        // Popping the element since it is going to next cell
        mainBoard[trackNumber][columnNumber].cellStack.pop();

        // Removing the last element of array so that after movement, displaying is correct.
        mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
        mainBoard[trackNumber][columnNumber].elementsCounter--;

        for (auto &playerIterator : playerVector)
        {
            if (hedgehog.find(playerIterator.getColor()) != -1)
            {
                cout << "\nBEFORE :: " << playerIterator.finishedHedgehogs;
                playerIterator.finishedHedgehogs++;
                cout << "\n\nAFTER :: " << playerIterator.finishedHedgehogs << endl;

                cout << "\nSPIDERMAN - A " << playerIterator.getColor() << " HEDGEHOG JUST CROSSED A FINISH LINE! GOOD JOBBBB!" << endl
                     << endl;

                displayBoard();

                return;
            }
        }
    }
    // CHECK IF WE ARE AT A BLACK HOLE OR NOT

    // B L A C K H O L E
    if (mainBoard[row][column].cellName.find("BLCKH") != -1)
    {
        cout << "\nSPIDERMAN - OH NO! " << hedgehog << " FELL INTO A BLACKHOLE! AWW YOU POOR THING!" << endl
             << endl;

        // Popping the element since it is going to next cell
        mainBoard[trackNumber][columnNumber].cellStack.pop();

        // Removing the last element of array so that after movement, displaying is correct.
        mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
        mainBoard[trackNumber][columnNumber].elementsCounter--;

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
    else if (mainBoard[row][column].cellName.find("WORMH") != -1)
    {

        cout << "\nSPIDERMAN - " << hedgehog << " FELL INTO A WORMHOLE! BYE BYE!\n";

        srand(time(0));
        int random = 1 + (rand() % 6);

        cout << "\nSPIDERMAN - "
             << "TRANSPORTING " << hedgehog << " TO THE STARTING OF TRACK " << random << endl;

        // Popping the element since it is going to next cell
        mainBoard[trackNumber][columnNumber].cellStack.pop();

        // Removing the last element of array so that after movement, displaying is correct.
        mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
        mainBoard[trackNumber][columnNumber].elementsCounter--;

        // TRANSPORTATION
        mainBoard[random][1].cellStack.push(hedgehog);

        // array index starts at 0, but I have made it to be the same as what the user chooses
        mainBoard[random][1].elementsDisplayerArray[mainBoard[random][1].elementsCounter] = hedgehog;

        // increasing the size of array since the player has moved to this new cell
        mainBoard[random][1].elementsCounter++;
    }

    // S H A L L O W - P I T
    else if (mainBoard[row][column].cellName.find("SHLWP") != -1)
    {
        // If the stack is empty that means the shallow pit has space for one hedgehog to trap.
        if (mainBoard[row][column].cellStack.empty() == 1)
        {

            cout << "\nSPIDERMAN - " << hedgehog << " FELL INTO A SHALLOWPIT";

            cout << "\nSPIDERMAN - AW YOU POOR THING!";

            cout << "\nSPIDERMAN - LOCKING PLAYER IN SHALLOW PIT! I AM SORRY DEAR PLAYER, BUT YOU CAN'T COME OUT UNTIL THE GAME ENDS!";

            // Putting the element in the cell selected by user
            mainBoard[row][column].cellStack.push(hedgehog);

            // array index starts at 0;
            mainBoard[row][column].elementsDisplayerArray[mainBoard[row][column].elementsCounter] = hedgehog;

            // increasing the size of array since the player has moved to this new cell
            mainBoard[row][column].elementsCounter++;

            // make accessibility false, because the hedgehog won't be accessible after falling into the shallow pit
            for (auto playerIterator : playerVector)
            {
                if (hedgehog.find(playerIterator.getColor()) != -1)
                {
                    playerIterator.hghPositionArray[hedgehogNumber - 1].accessible = false;
                }
            }
        }
        // Popping the element since it is going to next cell
        mainBoard[trackNumber][columnNumber].cellStack.pop();

        // Removing the last element of array so that after movement, displaying is correct.
        mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
        mainBoard[trackNumber][columnNumber].elementsCounter--;

        // After trapping the hedgehog, we want other hedgehogs to skip the shallow pit and go to the next cell, so we'll change the cells
        // But this only happens if and only if the shallow pit already has trapped a hedgehog!
        if (mainBoard[row][column].cellStack.empty() == 0)
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
            mainBoard[row][column].cellStack.push(hedgehog);

            // array index starts at 0;
            mainBoard[row][column].elementsDisplayerArray[mainBoard[row][column].elementsCounter] = hedgehog;

            // increasing the size of array since the player has moved to this new cell
            mainBoard[row][column].elementsCounter++;
        }
    }

    // D E E P - P I T
    else if (mainBoard[row][column].cellName.find("DEEPP") != -1)
    {
        mainBoard[row][column].deepPit.push(hedgehog);

        // Increment
        mainBoard[row][column].sizeOfDeepPit++;

        mainBoard[row][column].elementsDisplayerArray[mainBoard[row][column].elementsCounter] = hedgehog;
        mainBoard[row][column].elementsCounter++;

        // Popping the element since it is going to next cell
        mainBoard[trackNumber][columnNumber].cellStack.pop();

        // Removing the last element of array so that after movement, displaying is correct.
        mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
        mainBoard[trackNumber][columnNumber].elementsCounter--;

        // make accessibility false, because the hedgehog won't be accessible after falling into the deep pit
        for (auto playerIterator : playerVector)
        {
            if (hedgehog.find(playerIterator.getColor()) != -1)
            {
                playerIterator.hghPositionArray[hedgehogNumber - 1].accessible = false;
            }
        }

        if (mainBoard[row][column].sizeOfDeepPit == 3)
        {
            string poppedHgh = mainBoard[row][column].deepPit.front();
            string poppedHghNumberInString = poppedHgh.substr(poppedHgh.size() - 1, 1);
            string poppedHghName = poppedHgh.substr(0, poppedHgh.size() - 1);
            int poppedHedgehogNumber = stoi(poppedHghNumberInString);

            mainBoard[row][column].deepPit.pop();

            // Don't forget to decrement
            mainBoard[row][column].sizeOfDeepPit--;

            // Don't forget to add into elements counter
            mainBoard[row][column].elementsCounter--;

            // It's pretty tricky for deep pit.
            // Usually we are using the elementsDisplayerArray of cells class to show the components of a cells
            // I'll explain later
            int j = 0;
            for (int i = 1; i < mainBoard[row][column].elementsCounter; i++)
            {
                string temp = mainBoard[row][column].elementsDisplayerArray[i];
                mainBoard[row][column].elementsDisplayerArray[i] = '\0';
                mainBoard[row][column].elementsDisplayerArray[j] = temp;
                j++;
            }

            // Make the hedgehog accessible
            for (auto playerIterator : playerVector)
            {
                if (poppedHghName.find(playerIterator.getColor()) != -1)
                {
                    playerIterator.hghPositionArray[poppedHedgehogNumber - 1].accessible = true;
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
            mainBoard[row][column].cellStack.push(poppedHgh);

            // array index starts at 0;
            mainBoard[row][column].elementsDisplayerArray[mainBoard[row][column].elementsCounter] = poppedHgh;

            // increasing the size of array since the player has moved to this new cell
            mainBoard[row][column].elementsCounter++;
        }
    }
    // CHECK IF THE PLAYER IS TRYNA MOVE THE HEDGEHOG FROM THE DEEP PIT. THAT SHOULD NOT BE ALLOWED.
    else if (mainBoard[trackNumber][columnNumber].cellName.find("DEEPP") != -1)
    {
        cout << "\nSPIDERMAN - NU UH DEAR! YOU CAN'T MOVE YOUR HEDGEHOG! IT's TRAPPED IN A DEEP PIT. GOOD HEAVENS, WAIT FOR YOUR LUCK TO TURN AROUND!" << endl;
    }

    // N O R M A L - S T A C K I N G
    else
    {
        // IF IT IS A SHALLOW PIT, WE CAN'T LET THE LAST ELEMENT ESCAPE
        // HAHAHAHHAHAHHA
        // Configure this correctly, the hgh just jumped out
        if (mainBoard[trackNumber][columnNumber].cellName.find("SHLWP") != -1)
        {
            if (mainBoard[trackNumber][columnNumber].cellStack.empty() != 1 && mainBoard[trackNumber][columnNumber].cellStack.size() < 2)
            {

                cout << "\nSPIDERMAN - THE HEDGEHOG CAN'T MOVE BECAUSE IT IS STUCK IN THE SHALLOWPIT! RIP " << hedgehog;
            }

            else
            {
                // Popping the element since it is going to next cell
                mainBoard[trackNumber][columnNumber].cellStack.pop();

                // Removing the last element of array so that after movement, displaying is correct.
                mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
                mainBoard[trackNumber][columnNumber].elementsCounter--;

                // Putting the element in the cell selected by user
                mainBoard[row][column].cellStack.push(hedgehog);

                // array index starts at 0;
                mainBoard[row][column].elementsDisplayerArray[mainBoard[row][column].elementsCounter] = hedgehog;

                // increasing the size of array since the player has moved to this new cell
                mainBoard[row][column].elementsCounter++;
            }
        }

        else
        {
            // Popping the element since it is going to next cell
            mainBoard[trackNumber][columnNumber].cellStack.pop();

            //             // Removing the last element of array so that after movement, displaying is correct.
            mainBoard[trackNumber][columnNumber].elementsDisplayerArray[size - 1] = '\0';
            mainBoard[trackNumber][columnNumber].elementsCounter--;

            //             // Putting the element in the cell selected by user
            mainBoard[row][column].cellStack.push(hedgehog);

            //           // array index starts at 0;
            mainBoard[row][column].elementsDisplayerArray[mainBoard[row][column].elementsCounter] = hedgehog;

            // increasing the size of array since the player has moved to this new cell
            mainBoard[row][column].elementsCounter++;
            cout << "\n";

            if (player.intialMovement == -1)
            {
                player.intialMovement = 0;
            }
        }
    }
    cout << "\n";

    displayBoard();
}

void GameBoard ::printUserHhgPositionsInTheTrack(Player &player, int trackNumber)
{

    int j = 0;
    set<string> setOfTracks;
    for (int i = 1; i < 10; i++)
    {
        if (mainBoard[trackNumber][i].cellName == "DEEPP")
        {
        }
        if (mainBoard[trackNumber][i].cellName == "SHLWP")
        {
        }
        if (mainBoard[trackNumber][i].cellStack.empty() == 0)
        {
            // Adding plus 1 because we are storing row number in the parameter and for the user track numbers are starting from 1
            setOfTracks.insert("Track " + to_string(trackNumber) + ", Column " + to_string(i));
            j++;
        }
    }

    if (j == 0)
    {
        cout << "\nSPIDERMAN - LOOKS LIKE NO HEDGEHOGS ARE PRESENT FOR THE PLAYER!";
        return;
    }

    cout << "\nSPIDERMAN - YOUR HEDGEHOGS ARE ON THESE TRACKS, READY TO MOVE :: ";
    cout << endl;
    for (auto setIterator : setOfTracks)
    {
        cout << setIterator << endl;
    }
}