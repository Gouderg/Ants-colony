#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "constante.hpp"


class Wall {
    public: 
        // Constructor
        Wall();

        // Desctructor
        ~Wall();

        // Getter.
        uint8_t getWall(const int x, const int y) {return walls[y][x];}


        void addWall(int x, int y);
        void draw(sf::RenderWindow *window);

    private:
        uint8_t walls[(int) SIZE_H / SIZE_WALL][(int) SIZE_W / SIZE_WALL];

};