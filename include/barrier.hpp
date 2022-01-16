#pragma once

#include <iostream>
#include <vector>

#include "pvector.hpp"
#include <SFML/Graphics.hpp>


class Barrier {
    public: 
        // Constructor
        Barrier(const int x, const int y);

        // Desctructor
        ~Barrier();

        static void draw(sf::RenderWindow *window);

    private:
        static std::vector<PVector*> barrier;

};