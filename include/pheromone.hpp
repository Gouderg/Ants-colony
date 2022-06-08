#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "constante.hpp"
#include "pvector.hpp"

class Pheromone {

    public:
        // Constructor.
        Pheromone();

        // Getter.
        int getPheromone(const int x, const int y) {return this->pheromones[y][x];}

        // Setter.
        void addPheromone(const int x, const int y, const int value) {this->pheromones[y][x] += value;}
        void subPheromone(const int x, const int y) {this->pheromones[y][x] -= PHE_DECREASE;}
        void setPheromone(const int x, const int y, const int value) {this->pheromones[y][x] = value;}


        // Other.
        void draw(sf::RenderWindow *window);

        

    private:
        int pheromones[SIZE_H][SIZE_W];
};  