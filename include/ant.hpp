#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>


#include "pvector.hpp"

class Ant {
    public:
        
        // Constructor.
        // Ant(){};
        Ant(const int x, const int y);

        // Destructor.
        ~Ant();

        // Static.
        static const int getSizeW() {return size_ant_w;}
        static const int getSizeH() {return size_ant_h;}

        // Other.
        void draw(sf::RenderWindow *window);
    
    private:
        static const int size_ant_w = 5;
        static const int size_ant_h = 2;

        PVector velocity;   // Speed.
        PVector position;   // Position.
        int isFeed;         // With or Without feed. 
};  