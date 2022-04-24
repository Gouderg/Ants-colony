#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "pheromone.hpp"
#include "constante.hpp"
#include "pvector.hpp"
#include "food.hpp"
#include "ant.hpp"
#include "wall.hpp"

class Colony {
    public:

        // Constructor.
        Colony();

        // Other.
        void draw(sf::RenderWindow *window);
        void createAnts();
        void update(Food *foods, Wall walls);

        // Getter.
        std::vector<Ant*> getAnts() {return this->ants;}
    
    private:
        PVector colony_center;
        std::vector<Ant*> ants;
        Pheromone phe;
        int nb_ants;
};