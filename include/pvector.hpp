#pragma once

#include <iostream>

class PVector {
    public:
        // Constructor.
        PVector(){};
        PVector(const int x, const int y);

        // Destructor.
        ~PVector();

        // Getter.
        int getX() const {return this->x;}
        int getY() const {return this->y;}

        // Setter.
        void setX(const int x) {this->x = x;}
        void setY(const int y) {this->y = y;}

    private:
        int x, y;
};