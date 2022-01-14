#include "../include/colony.hpp"

Colony::Colony(){
    // Initialize colony in the middle
    
    int x = SIZE_W / 2 - this->colony_size;
    int y = SIZE_H / 2 - this->colony_size;

    this->colony_center = PVector(x, y);
}

void Colony::draw(sf::RenderWindow *window) {
    sf::CircleShape center;
    center.setRadius(this->colony_size);
    center.setPosition(this->colony_center.getX(), this->colony_center.getY());
    window->draw(center);
}