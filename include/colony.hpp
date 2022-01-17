#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "pvector.hpp"

class Colony {
    public:
        const int SIZE_W = 1200;
        const int SIZE_H = 900;

        // Constructor.
        Colony();

        // Other.
        void draw(sf::RenderWindow *window);

        // Static function
        static const int getColonySize() {return colony_size;}
    
    private:
        static const int colony_size = 10; // Size of colony in pixel

        PVector colony_center;
};