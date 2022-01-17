#include "../include/colony.hpp"

Colony::Colony(){

    // Initialize colony in the middle.
    int x = SIZE_W / 2 - this->colony_size;
    int y = SIZE_H / 2 - this->colony_size;
    this->colony_center = PVector(x, y);

    // Create all Ants.
    for (int i = 0; i < number_ants; i++) {
        Ant* ant = new Ant(rand() % SIZE_W, rand() % SIZE_H);

        ants.push_back(ant);
    }
}

void Colony::draw(sf::RenderWindow *window) {
    sf::CircleShape center;
    center.setRadius(this->colony_size);
    center.setPosition(this->colony_center.getX(), this->colony_center.getY());
    window->draw(center);

    for (auto ant: ants) {
        ant->draw(window);
    }
}