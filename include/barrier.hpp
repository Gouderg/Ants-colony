#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <algorithm>

#include "pvector.hpp"
#include "wall.hpp"


class Barrier {
    public: 
        // Constructor
        Barrier();

        // Desctructor
        ~Barrier();

        // Getter.
        std::vector<Wall*> getBarrier() {return barrier;}


        void addWall(const int x, const int y);
        void draw(sf::RenderWindow *window);

    private:
        std::vector<Wall*> barrier;

};