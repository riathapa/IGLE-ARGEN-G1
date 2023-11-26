#ifndef SQUARE_H
#define SQUARE_H

// #include "Player.h"

#include <string>
#include <iostream>
#include <iomanip>



//LEVEL 1 CLASS
class Square {
    public:
        Square() = default;
        virtual ~Square() = default;

        virtual void display();
        // virtual void print(vector<Player> &players, int numberOfPlayers);
};

#endif