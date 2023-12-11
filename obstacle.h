#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Square.h"

class GameBoard;
class Obstacle : public GameBoard {

private:
   std::string label;    

public:
    Obstacle(const std::string& label) : label(label) {}
};

#endif 
