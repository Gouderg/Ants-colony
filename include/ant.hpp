#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


#include "pvector.hpp"

class Ant {
    public:
        
        // Constructor.
        // Ant(){};
        Ant(const int witdh, const int height);

        // Destructor.
        ~Ant();

        void draw(sf::RenderWindow *window);
    
    private:
        PVector velocity;   // Speed.
        PVector position;   // Position.
        int isFeed;         // With or Without feed. 
};  