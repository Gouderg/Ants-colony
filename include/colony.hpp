#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


#include "pvector.hpp"
#include "ant.hpp"


#define SIZE_W 1200
#define SIZE_H 900

class Colony {
    public:
        // static const int SIZE_W = 1200;
        // static const int SIZE_H = 900;

        // Constructor.
        Colony();

        // Other.
        void draw(sf::RenderWindow *window);

        // Static function
        static const int getColonySize() {return colony_size;}
        static const int getNumberAnts() {return number_ants;}
    
    private:
        static const int colony_size = 10;      // Size of colony in pixel.
        static const int number_ants = 200;     // Number of ants.

        PVector colony_center;
        std::vector<Ant*> ants;
};