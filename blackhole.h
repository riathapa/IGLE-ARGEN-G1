#ifndef BLACK_HOLE_H
#define BLACK_HOLE_H

#include "Obstacle.h"

class BlackHole : public Obstacle {
public:
    BlackHole(const std::string& label) : Obstacle(label) {}
};

#endif
