#pragma once

#include <iostream>
#include <cmath>

#define PI 3.14159265

class PVector {
    public:
        // Constructor.
        PVector(){};
        PVector(const double x, const double y);

        // Destructor.
        ~PVector();

        // Getter.
        double getX() const {return this->x;}
        double getY() const {return this->y;}

        // Setter.
        void setX(const double x) {this->x = x;}
        void setY(const double y) {this->y = y;}

        // Other.
        void rotate(double angle, double x_pivot, double y_pivot);
        static double COS(const double angle);
        static double SIN(const double angle);
        static PVector velocity(const int direction, const int speed);
        static bool equal(PVector v1, PVector v2);

        // Add.
        void add(PVector v);
        static PVector add(PVector v1, PVector v2);

    private:
        double x, y;
};