#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "pheromone.hpp"
#include "constante.hpp"
#include "pvector.hpp"
#include "food.hpp"
#include "ant.hpp"

class Colony {
    public:

        // Constructor.
        Colony();

        // Other.
        void draw(sf::RenderWindow *window);
        void createAnts();
        void update(sf::RenderWindow *window, Food *foods);
        void popPheromone(int index);
        static void addPheromone(PVector p, int depot);

        // Getter.
        std::vector<Ant*> getAnts() {return this->ants;}
    
    private:
        PVector colony_center;
        std::vector<Ant*> ants;
        std::vector<Pheromone*> pheromones;
        int nb_ants;
};