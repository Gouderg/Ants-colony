#pragma once

#include <iostream>

#include "pvector.hpp"

class Wall {
    public:
        // Constructor
        Wall(const int x, const int y);

        // Destructor
        ~Wall();

        // Getter.
        PVector getPos() const {return this->position;}
        static const int getSize() {return size;}

        // Setter.
        void setPos(const PVector pos) {this->position = pos;}


    private:
        PVector position;
        static const int size = 1;
};