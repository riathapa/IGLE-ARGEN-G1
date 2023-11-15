#ifndef WORM_HOLE_H
#define WORM_HOLE_H

#include "Obstacle.h"

class WormHole : public Obstacle {
public:
    WormHole(const std::string& label) : Obstacle(label) {}
};

#endif 
