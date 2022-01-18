#pragma once

#include <iostream>
#include <cmath>

#define PI 3.14159265

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

        // Other.
        void rotate(int angle, int x_pivot, int y_pivot);
        static double COS(int angle);
        static double SIN(int angle);

        // Add.
        void add(PVector v);

    private:
        int x, y;
};