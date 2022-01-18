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
        static const int size_ant_w = 4;
        static const int size_ant_h = 4;
        static const int max_angle = 180;



        PVector velocity;   // Speed.
        PVector position;   // Position.
        // Direction angle.
        // Sense angle.
        // Sense direction.


        int isFeed;         // With or Without feed. 
};  