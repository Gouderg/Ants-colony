#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "constante.hpp"
#include "pvector.hpp"

class Pheromone {

    public:
        // Constructor.
        Pheromone(const PVector p, const int depot);

        // Getter.
        PVector getPosition() {return this->position;}
        int getDepot() {return this->depot;}

        // Setter.
        void setPositon(const PVector p) {this->position = p;}
        void setDepot(const int depot) {this->depot = depot;}

        // Other.
        void draw(sf::RenderWindow *window);

        

    private:
        PVector position;
        int depot;

};  