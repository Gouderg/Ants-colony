#include "../include/pvector.hpp"

PVector::PVector(const int x, const int y) {
    this->x = x;
    this->y = y;
}

PVector::~PVector() {
    // std::cout << "Pvector desctructor" << std::endl;
}

void PVector::rotate(int angle, int x_pivot, int y_pivot) {
    int x = this->x - x_pivot;
    int y = this->y - y_pivot;

    this->x = (int) (x_pivot + (x*PVector::COS(angle) - y*SIN(angle)));
    this->y = (int) (y_pivot + (x*PVector::SIN(angle) + y*COS(angle)));
}


double PVector::COS(int angle) {
    return cos(angle * PI/180);
}

double PVector::SIN(int angle) {
    return sin(angle * PI/180);
}