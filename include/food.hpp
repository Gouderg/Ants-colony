#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "constante.hpp"



class Food {
    public:
        // Constructor.
        Food();
    
        // Getter.
        uint8_t getFood(const int x, const int y) {return this->foods[y][x];}

        // Other.
        void add(const int x, const int y);
        void draw(sf::RenderWindow *window);
    
    private:
        uint8_t foods[(int) SIZE_H / SIZE_FOOD_PIXEL][(int) SIZE_W / SIZE_FOOD_PIXEL];

};