#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <algorithm>

#include "pvector.hpp"


class Wall {
    public: 
        // Constructor
        Wall();

        // Desctructor
        ~Wall();

        // Getter.
        int getWall(const int x, const int y) {return walls[y][x];}


        void addWall(int x, int y);
        void draw(sf::RenderWindow *window);

    private:
        int walls[(int) SIZE_H / SIZE_WALL][(int) SIZE_W / SIZE_WALL];

};