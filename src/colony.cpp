#include "../include/colony.hpp"

Colony::Colony(){

    // Initialize colony in the middle.
    int x = SIZE_W / 2 - SIZE_COLONY;
    int y = SIZE_H / 2 - SIZE_COLONY;
    this->colony_center = PVector(x, y);

    // Create all Ants.
    for (int i = 0; i < NB_ANTS_CREATION; i++) {
        Ant* ant = new Ant(rand() % 50 + SIZE_W/2 - 25, rand() % 50 + SIZE_H/2 - 25, rand() % 360, ANT_SPEED);
        ants.push_back(ant);
    }

    this->nb_ants = NB_ANTS_CREATION;
}

void Colony::createAnts() {
    Ant* ant = new Ant(SIZE_W/2, SIZE_H/2, rand() % 360, 2);
    ants.push_back(ant);
}

void Colony::update(sf::RenderWindow *window, Food *foods) {

    // Add new ants which time.
    if (this->nb_ants < NB_ANTS) {
        createAnts();
        this->nb_ants += 1;
    }


    // Update each ants.
    for (auto ant: getAnts()) {
		ant->update(foods, &this->pheromones);
		ant->draw(window);
	}
    
    // Decrease pheromone trail intensity with time.

    for (int i = this->pheromones.size()-1; i >= 0; i--) {
        int dep = this->pheromones[i]->getDepot();
        dep -= PHE_DECREASE;

        if (dep <= 0) {
            this->pheromones.erase(this->pheromones.begin()+i);
        } else {
            this->pheromones[i]->setDepot(dep);
        }
    }
}


void Colony::draw(sf::RenderWindow *window) {
    sf::CircleShape center;
    center.setRadius(SIZE_COLONY);
    center.setPosition(this->colony_center.getX(), this->colony_center.getY());
    center.setOutlineThickness(OUT_SIZE_COLONY);
    center.setOutlineColor(sf::Color::Yellow);
    center.setFillColor(sf::Color::Transparent);
    window->draw(center);

    for (auto ant: ants) {
        ant->draw(window);
    }

    for (auto phe: pheromones) {
        phe->draw(window);
    }
}