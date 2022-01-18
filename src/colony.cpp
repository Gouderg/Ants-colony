#include "../include/colony.hpp"

Colony::Colony(){

    // Initialize colony in the middle.
    int x = SIZE_W / 2 - SIZE_COLONY;
    int y = SIZE_H / 2 - SIZE_COLONY;
    this->colony_center = PVector(x, y);

    // Create all Ants.
    for (int i = 0; i < NB_ANTS; i++) {
        Ant* ant = new Ant(rand() % SIZE_W, rand() % SIZE_H, rand() % 4 - 2, rand() % 4 - 2);

        ants.push_back(ant);
    }
}

void Colony::draw(sf::RenderWindow *window) {
    sf::CircleShape center;
    center.setRadius(SIZE_COLONY);
    center.setPosition(this->colony_center.getX(), this->colony_center.getY());
    window->draw(center);

    for (auto ant: ants) {
        ant->draw(window);
    }
}