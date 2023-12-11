#ifndef CELLS_H_
#define CELLS_H_

#include <stack>
#include<queue>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class Cells{
    
    public:
        string elementsDisplayerArray[6];
        int elementsCounter = 0;
        stack<string> cellStack;
        string cellName;

        queue<string> deepPit;
        int sizeOfDeepPit = 0 ;

        void displayElementsOnBoard();
        void displayElementsOnBoard(ofstream &ofObj);
};

#endif