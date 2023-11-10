#include<iostream>
using namespace std;

#include "Board.h"
#include "Dice.h"
#include "Dice.cpp"
#include "Player.h"


int main(){
    
    cout << "\n   WELCOME TO IGLE ARGEN\n"; 
    cout << "----------------------------"; 

    Dice randomGen;

    cout << "\nRandom number between 1 and 6: " << randomGen.getRandomNumber() << endl;

    return 0;
}