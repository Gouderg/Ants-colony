#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>



#include "pvector.hpp"
#include "constante.hpp"



class Food {
    public:
        // Constructor.
        Food();
    
        // Getter.
        std::vector<PVector> getFood() const {return this->foods;}


        // Other.
        void pop(int index);
        void draw(sf::RenderWindow *window);
    
    private:
        std::vector<PVector> foods;

};