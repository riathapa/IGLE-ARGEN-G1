#ifndef CELLS_H_
#define CELLS_H_

#include "Player.h"

#include <stack>
#include<queue>
#include <string>
#include <iostream>

using namespace std;

class Cells{
    
    public:
        string elementsDisplayerArray[6];
        int elementsCounter = 0;
        stack<string> cellStack;
        string cellName;

        queue<string> deepPit;
        int sizeOfDeepPit = 0 ;

        bool finishLine = false;

        void displayElementsOnBoard();
};

#endif