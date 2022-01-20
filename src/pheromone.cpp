#include "../include/pheromone.hpp"

Pheromone::Pheromone(const PVector p, const int depot) {
    this->position = p;
    this->depot = depot;
}

void Pheromone::draw(sf::RenderWindow *window) {
    sf::CircleShape phe(SIZE_PHEROMONE_DIFFUSION);
    phe.setFillColor(sf::Color(255, 0, 0, this->depot));
    phe.setPosition(this->position.getX(), this->position.getY());

    window->draw(phe);
}   