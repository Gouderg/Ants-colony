#pragma once

#include <iostream>

#include "constante.hpp"
#include "pvector.hpp"

class Wall {
    public:
        // Constructor
        Wall(const int x, const int y);

        // Destructor
        ~Wall();

        // Getter.
        PVector getPos() const {return this->position;}

        // Setter.
        void setPos(const PVector pos) {this->position = pos;}


    private:
        PVector position;
};