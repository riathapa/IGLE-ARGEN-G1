#include "GameBoard.h"
#include "Cells.h"
#include "HghPositions.h"
#include "Cells.cpp"

#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iomanip>
#include <stack>
using namespace std;

GameBoard::GameBoard(int tracks, int columns) : tracks(tracks), columns(columns)
{
    tracks = tracks;
    columns = columns;
    // board.resize(tracks);
    // for (auto &row : board) {
    //     row.resize(columns); // Initialize each column in each track
    // }
}

void GameBoard::initializeBoard()
{

    mainBoard = new Cells *[tracks];

    for (int i = 0; i < columns; i++)
    {
        mainBoard[i] = new Cells[columns];
    }

    for (int t = 0; t < tracks; ++t)
    {

        mainBoard[t][0].cellName = "T" + to_string(t + 1) + "S"; // Start squares

        for (int c = 1; c < columns - 1; ++c)
        {
            // string label = "T" + to_string(t + 1) + static_cast<char>('a' + c - 1);

            // Push label to stack for middle squares
            mainBoard[t][c].cellName = "___";
        }

        // mainBoard[t][columns - 1].cellName = "T" + to_string(t + 1) + "Z"; // Goal squares
        mainBoard[t][columns - 1].cellName = "| FINISH LINE | "; // Goal squares
    }
}

void GameBoard ::placeObstacles()
{

    // MAKE OBSTACLES RANDOM

    // vector<int> columnIndices;
    // columnIndices.resize(columns - 3, columns);
    // Exclude first, last, and second columns
    // vector<int> columnIndices;
    // cout << "";
    // columnIndices.resize(columns - 3);

    // // Initialize with numbers from 2 to columns - 2
    // std::iota(columnIndices.begin(), columnIndices.end(), 2);

    // std::random_device rd;
    // std::mt19937 g(rd());
    // std::shuffle(columnIndices.begin(), columnIndices.end(), g);
    // cout << "\n1";
    // int j = 2;
    // for (int t = 0; t < tracks; ++t)
    // {

    //     if(t==3){
    //         continue;
    //     }
    //     if(t==1){
    //         continue;
    //     }
    //     // Ensure no two obstacles are in the same column
    //     // Cycle through shuffled indices
    //     // int obstacleColumn = columnIndices[t % columnIndices.size()];

    //     // Place obstacle with a unique label
    //     mainBoard[t][j].cellName = "X1";
    //     j++;
    // }

    mainBoard[0][1].cellName = "WORMH";
    mainBoard[1][6].cellName = "WORMH";
    mainBoard[2][4].cellName = "SHLWP";
    mainBoard[3][7].cellName = "DEEPP";
    mainBoard[4][5].cellName = "WORMH";
    mainBoard[5][3].cellName = "BLCKH";
}

void GameBoard::displayBoard()
{

    for (int i = 0; i < tracks; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (mainBoard[i][j].cellName.find("SHLWP") != -1)
            {
                if (mainBoard[i][j].elementsCounter == 0)
                {
                    cout << mainBoard[i][j].cellName << "               ";
                }

                else {
                    cout << mainBoard[i][j].cellName << "+";
                    mainBoard[i][j].displayElementsOnBoard();
                }
            }
            else if (mainBoard[i][j].elementsCounter == 0)
            {
                cout << mainBoard[i][j].cellName << "               ";
            }
            else
            {
                mainBoard[i][j].displayElementsOnBoard();
            }
        }

        cout << endl
             << endl;
    }
}

// // void GameBoard::dBoard() {
// //     for (const auto& row : board) {
// //         for (const auto& stack : row) {
// //             if (!stack.empty()) {
// //                 std::cout << std::setw(5) << stack.top(); // Display top of the stack
// //             } else {
// //                 std::cout << std::setw(5) << " "; // Display placeholder for empty stack
// //             }
// //         }
// //         std::cout << std::endl;
// //     }
// // }

// void GameBoard::placeHedgehogAt(int track, const std::string& color) {
//     for (int level = 0; level < columns; ++level) {
//         if (board[track][level].empty() || level == 0) {
//             board[track][level].push(color); // Place hedgehog in the first empty spot
//             break;
//         }
//     }
// }

void GameBoard::placeHedgehogInStartColumn(int track, const string &color, int playerCounter, HghPositions hghPositionArray[])
{
    // Place hedgehog in the first available spot in the start column
    // This stack maintains the elements
    mainBoard[track][0].cellStack.push(color + to_string(playerCounter));

    // This array is uses to show the players the placement of all their hedgehogs and in order, with the right side representing the top of the stack
    mainBoard[track][0].elementsDisplayerArray[mainBoard[track][0].elementsCounter] = color + to_string(playerCounter);

    mainBoard[track][0].elementsCounter++;

    // Tracking the position of the hedgehog also and saving it in a dynamic array made of class HghPositions. Declared in Player class.
    hghPositionArray[playerCounter - 1].trackNumber = track - 1;
    hghPositionArray[playerCounter - 1].columnNumber = 0;

    // Adding cout because the program starts running out of memory idk why
    cout << " " << endl;
}

bool GameBoard ::checkPresenceOfHedgeHog(int trackNumber)
{
    for (int i = 0; i < 9; i++)
    {
        if (mainBoard[trackNumber][i].cellStack.empty() == 0)
        {
            return true;
        }
    }

    return false;
}