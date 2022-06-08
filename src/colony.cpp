#include "../include/colony.hpp"

Colony::Colony(){

    // Initialize colony in the middle.
    int x = SIZE_W / 2 - SIZE_COLONY;
    int y = SIZE_H / 2 - SIZE_COLONY;
    this->colony_center = PVector(x, y);

    // Create all Ants.
    for (int i = 0; i < NB_ANTS_CREATION; i++) {
        Ant* ant = new Ant(rand() % 50 + SIZE_W/2 - 25, rand() % 50 + SIZE_H/2 - 25, rand() % 5 - 2, rand() % 5 - 2);
        ants.push_back(ant);
    }

    this->nb_ants = NB_ANTS_CREATION;
}

void Colony::createAnts() {
    Ant* ant = new Ant(SIZE_W/2, SIZE_H/2, rand() % 5 - 2, rand() % 5 - 2);
    ants.push_back(ant);
}

void Colony::update(Food *foods, Wall walls) {

    // Add new ants which time.
    if (this->nb_ants < NB_ANTS) {
        createAnts();
        this->nb_ants += 1;
    }

    // Pheromone temp.
    Pheromone* phe_tour = new Pheromone();
    Pheromone* phe_nb_ants = new Pheromone();



    // // Update each ants.
    for (auto ant: getAnts()) {
		ant->update(foods, &(this->phe), walls, phe_tour, phe_nb_ants);

	}
    
    // Decrease pheromone trail intensity with time.
    int val = 0;
    for (int i = 0; i < SIZE_H; i++) {
        for (int j = 0; j < SIZE_W; j++) {
            if (phe_nb_ants->getPheromone(j, i) > 0) {
                val = (1 - PHE_EVAPORATION_COEFFICIENT) * this->phe.getPheromone(j, i) + (phe_tour->getPheromone(j, i) / phe_nb_ants->getPheromone(j, i));
                val = (val > PHE_MAX) ? 255 : val;
            } else {
                val = (1 - PHE_EVAPORATION_COEFFICIENT) * this->phe.getPheromone(j, i);
            } 
            this->phe.setPheromone(j, i, val);
        }
    }

    // Desallocate pointer. 
    free(phe_tour);
    free(phe_nb_ants);


}


void Colony::draw(sf::RenderWindow *window) {

    // Draw circle.
    sf::CircleShape center;
    center.setRadius(SIZE_COLONY);
    center.setPosition(this->colony_center.getX(), this->colony_center.getY());
    center.setOutlineThickness(OUT_SIZE_COLONY);
    center.setOutlineColor(sf::Color::Yellow);
    center.setFillColor(sf::Color::Transparent);
    window->draw(center);

    // Draw ants.
    for (auto ant: ants) {
        ant->draw(window);
    }

    // Draw pheromones.
    phe.draw(window);
}