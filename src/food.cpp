#include "../include/food.hpp"


Food::Food() {
    // Place square in each corner.
    
    // Top left.
    for (int i = 0; i < NB_FOOD * SIZE_FOOD_PIXEL; i += SIZE_FOOD_PIXEL) {
        for (int j = 0; j < NB_FOOD * SIZE_FOOD_PIXEL; j += SIZE_FOOD_PIXEL) {
            this->foods.push_back(PVector(i,j));
        }
    }

    // Top right.
    for (int i = SIZE_W - NB_FOOD * SIZE_FOOD_PIXEL; i < SIZE_W; i += SIZE_FOOD_PIXEL) {
        for (int j = 0; j < NB_FOOD * SIZE_FOOD_PIXEL; j += SIZE_FOOD_PIXEL) {
            this->foods.push_back(PVector(i,j));
        }
    }

    // Bottom left.
    for (int i = 0; i < NB_FOOD * SIZE_FOOD_PIXEL ; i += SIZE_FOOD_PIXEL) {
        for (int j = SIZE_H - NB_FOOD * SIZE_FOOD_PIXEL; j < SIZE_H; j += SIZE_FOOD_PIXEL) {
            this->foods.push_back(PVector(i,j));
        }
    }

    // Bottom right.
    for (int i = SIZE_W - NB_FOOD * SIZE_FOOD_PIXEL; i < SIZE_W; i += SIZE_FOOD_PIXEL) {
        for (int j = SIZE_H - NB_FOOD * SIZE_FOOD_PIXEL; j < SIZE_H; j += SIZE_FOOD_PIXEL) {
            this->foods.push_back(PVector(i,j));
        }
    }
}

void Food::pop(int index) {
    this->foods.erase(this->foods.begin()+index);
}

void Food::draw(sf::RenderWindow *window) {

    for (auto food: foods) {
        sf::RectangleShape f_square(sf::Vector2f(SIZE_FOOD_PIXEL, SIZE_FOOD_PIXEL));
        f_square.setPosition(food.getX(), food.getY());
        f_square.setFillColor(sf::Color::Green);
        window->draw(f_square);
    }
}
