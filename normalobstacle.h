#ifndef NORMAL_OBSTACLE_H
#define NORMAL_OBSTACLE_H
#include "Obstacle.h"

class NormalObstacle : public Obstacle {
public:
    NormalObstacle(const std::string& label) : Obstacle(label) {}
};

#endif 
