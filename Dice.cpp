#include <iostream>
#include "Dice.h"

int Dice::roll()
{
    srand(time(0));
    int random = 1 + (rand() % 6);
    return random;
}