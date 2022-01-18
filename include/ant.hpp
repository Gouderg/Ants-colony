#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "constante.hpp"
#include "pvector.hpp"

class Ant {
    public:
        
        // Constructor.
        // Ant(){};
        Ant(const int x, const int y, const int vx, const int vy);

        // Destructor.
        ~Ant();

        // Other.
        void draw(sf::RenderWindow *window);

        void update();
        int checkBorder();

    
    private:
        static const int max_angle = 180;

        PVector velocity;   // Speed.
        PVector position;   // Position.
        // Direction angle.
        // Sense angle.
        // Sense direction.


        int isFeed;         // With or Without feed. 
};  