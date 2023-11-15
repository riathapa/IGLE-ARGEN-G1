#ifndef NORMAL_SQUARE_H
#define NORMAL_SQUARE_H
#include "Square.h"


class NormalSquare : public Square {
private:
    std::string label;

public:
    NormalSquare(const std::string& label): label(label) {}

    void display() const override {
        std::cout << std::setw(5) << label;
    }
};

#endif
