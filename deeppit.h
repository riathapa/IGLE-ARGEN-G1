#ifndef DEEP_PIT_H
#define DEEP_PIT_H
#include "Obstacle.h"

class DeepPit : public Obstacle {
public:
    DeepPit(const std::string& label) : Obstacle(label) {}
};

#endif 
