#include <iostream>
#include <string>
using namespace std;

#include "Cells.h"

void Cells :: displayElementsOnBoard(){
    for(int i = 0; i<elementsCounter; i++){

        if(i < elementsCounter && i > elementsCounter -2){
            cout << elementsDisplayerArray[i] << "   ";
        }
        else {
            cout << elementsDisplayerArray[i] << ",";
        }
        
    }
}