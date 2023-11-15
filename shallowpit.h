#ifndef SHALLOW_PIT_H
#define SHALLOW_PIT_H

#include "Obstacle.h"

class ShallowPit : public Obstacle {
public:
    ShallowPit(const std::string& label) : Obstacle(label) {}
};

#endif 
