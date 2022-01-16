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

        void draw(sf::RenderWindow *window);
    
    private:
        const int colony_size = 10; // Size of colony in pixel

        PVector colony_center;
};