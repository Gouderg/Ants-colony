#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

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

        // Getter.
        std::vector<Ant*> getAnts() {return this->ants;}
    
    private:
        PVector colony_center;
        std::vector<Ant*> ants;
        int nb_ants;
};