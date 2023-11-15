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

// -----------------------------x-----------------------------x----------------------------

//LEVEL 2 HIERARCHY
class NormalSquare : public Square {

    private:
        std::string label;

    public:
        NormalSquare(const std::string& label): label(label) {}

        void display() const override {
            std::cout << std::setw(5) << label;
    }
};

//LEVEL 2 HIERARCHY
class Obstacle : public Square {

     private:
        std::string label;

    public:
        Obstacle(const std::string& label) : label(label) {}
        virtual void display() const override {
            std::cout << std::setw(5) << label;
        }
};

// -----------------------------x-----------------------------x----------------------------

//LEVEL 3 HEIRARCHY

//NORMAL OBSTACLE
class NormalObstacle : public Obstacle {
public:
    NormalObstacle(const std::string& label) : Obstacle(label) {}
};

//SHALLOW PIT
class ShallowPit : public Obstacle {
public:
    ShallowPit(const std::string& label) : Obstacle(label) {}
};

///DEEP PIT
class DeepPit : public Obstacle {
public:
    DeepPit(const std::string& label) : Obstacle(label) {}
};

//WORMHOLE
class WormHole : public Obstacle {
public:
    WormHole(const std::string& label) : Obstacle(label) {}
};

//BLACKHOLE
class BlackHole : public Obstacle {
public:
    BlackHole(const std::string& label) : Obstacle(label) {}
};


#endif 