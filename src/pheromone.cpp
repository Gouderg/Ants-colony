#include "../include/pheromone.hpp"

Pheromone::Pheromone() {
    for (int i = 0; i < SIZE_H; i++) {
        for (int j = 0; j < SIZE_W; j++) {
            this->pheromones[i][j] = 0;
        }
    }
}

void Pheromone::draw(sf::RenderWindow *window) {
    for (int i = 0; i < SIZE_H; i++) {
        for (int j = 0; j < SIZE_W; j++) {
            if (this->pheromones[i][j] > 0) {
                sf::CircleShape phe(PHE_DIFFUSION);
                phe.setFillColor(sf::Color(255, 0, 0, this->pheromones[i][j]));
                phe.setPosition(j, i);
                window->draw(phe);
            }
        }
    }
}   