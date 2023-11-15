#include "GameBoard.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iomanip>

GameBoard::GameBoard(int tracks, int columns) : tracks(tracks), columns(columns) {
    board.resize(tracks, std::vector<std::string>(columns, " ")); 
}

void GameBoard::initializeBoard() {
    for (int t = 0; t < tracks; ++t) {
        board[t][0] = "T" + std::to_string(t + 1) + "S"; // Start squares
        for (int c = 1; c < columns - 1; ++c) {
            board[t][c] = "T" + std::to_string(t + 1) + static_cast<char>('a' + c - 1); 
        }
        board[t][columns - 1] = "T" + std::to_string(t + 1) + "Z"; 
    }
}

void GameBoard::placeObstacles() {
    std::vector<int> columnIndices(columns - 3); 
    std::iota(columnIndices.begin(), columnIndices.end(), 2); 

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(columnIndices.begin(), columnIndices.end(), g);

    for (int t = 0; t < tracks; ++t) {
        
        int obstacleColumn = columnIndices[t % columnIndices.size()]; 
        board[t][obstacleColumn] = "Obs" + std::to_string(obstacleColumn - 1); 
    }
}

void GameBoard::displayBoard() {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            std::cout << std::setw(5) << cell;
        }
        std::cout << std::endl;
    }
}