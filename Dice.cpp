#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "Dice.h"

// void Dice::roll() {
//     std::srand(std::time(0));
// }

int Dice::getRandomNumber() {
    return (std::rand() % (6 - 1 + 1)) + 1; // min is 1 and max is 6
}