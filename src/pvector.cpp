#include "../include/pvector.hpp"

PVector::PVector(const double x, const double y) {
    this->x = x;
    this->y = y;
}

PVector::~PVector() {
    // std::cout << "Pvector desctructor" << std::endl;
}

void PVector::rotate(double angle, double x_pivot, double y_pivot) {
    int x = this->x - x_pivot;
    int y = this->y - y_pivot;

    this->x = x_pivot + (x*PVector::COS(angle) - y*SIN(angle));
    this->y = y_pivot + (x*PVector::SIN(angle) + y*COS(angle));
}

double PVector::COS(const double angle) {
    return cos(angle * PI/180);
}

double PVector::SIN(const double angle) {
    return sin(angle * PI/180);
}

void PVector::add(PVector v) {
    this->x += v.x;
    this->y += v.y;
}

PVector PVector::add(PVector v1, PVector v2) {
    PVector v = PVector(0,0);
    v.setX(v1.getX() + v2.getX());
    v.setY(v1.getY() + v2.getY());

    return v;
}

bool PVector::equal_for_food(PVector v1, PVector v2) {
    return (v1.getX() >= v2.getX() && v1.getX() <= v2.getX() + SIZE_FOOD_PIXEL && 
            v1.getY() >= v2.getY() && v1.getY() <= v2.getY() + SIZE_FOOD_PIXEL);
}


PVector PVector::velocity(const int direction, const int speed) {
    return PVector(speed * COS(direction), speed * SIN(direction));
}