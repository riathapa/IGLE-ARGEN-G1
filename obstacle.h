#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Square.h"

class Obstacle : public Square {

private:
   std::string label;    

public:
    Obstacle(const std::string& label) : label(label) {}
    virtual void display() const override {
        std::cout << std::setw(5) << label;
    }
};

#endif 
