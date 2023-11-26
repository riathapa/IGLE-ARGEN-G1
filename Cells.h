#ifndef CELLS_H_
#define CELLS_H_

#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Cells{
    
    public:
        string elementsDisplayerArray[6];
        int elementsCounter = 0;
        stack<string> cellStack;
        string cellName;

        void displayElementsOnBoard();
};

#endif