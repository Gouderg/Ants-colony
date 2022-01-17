#include "../include/wall.hpp"

Wall::Wall(const int x, const int y) {
    this->position = PVector(x,y);
}

Wall::~Wall() {
    // std::cout << "Appel du destructeur de Wall" << std::endl;
}