#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <iostream>
#include <iomanip>

//LEVEL 1 CLASS
class Square {
    public:
        Square() = default;
        virtual ~Square() = default;

        virtual void display() const = 0;
};

#endif