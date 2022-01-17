#include "../include/pvector.hpp"

PVector::PVector(const int x, const int y) {
    this->x = x;
    this->y = y;
}

PVector::~PVector() {
    // std::cout << "Pvector desctructor" << std::endl;
}