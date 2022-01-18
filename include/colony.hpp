#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "constante.hpp"
#include "pvector.hpp"
#include "ant.hpp"


#define SIZE_W 1200
#define SIZE_H 900

class Colony {
    public:

        // Constructor.
        Colony();

        // Other.
        void draw(sf::RenderWindow *window);

        // Getter.
        std::vector<Ant*> getAnts() {return this->ants;}
    
    private:
        PVector colony_center;
        std::vector<Ant*> ants;
};