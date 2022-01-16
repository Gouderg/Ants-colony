#include "../include/ant.hpp"

Ant::Ant(const int witdh, const int height) {
    this->velocity = PVector(0,0);
    this->position = PVector(witdh / 2, height / 2);
}

Ant::~Ant() {
    std::cout << "Ant destructor" << std::endl;
}

void Ant::draw(sf::RenderWindow *window) {

}
