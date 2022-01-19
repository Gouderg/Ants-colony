#include "../include/food.hpp"


Food::Food() {
    // Place square in each corner.
    
    // Top left.
    for (int i = 0; i < SIZE_FOOD; i++) {
        for (int j = 0; j < SIZE_FOOD; j++) {
            this->foods.push_back(PVector(i,j));
        }
    }

    // Top right.
    for (int i = SIZE_W - SIZE_FOOD; i < SIZE_W; i++) {
        for (int j = 0; j < SIZE_FOOD; j++) {
            this->foods.push_back(PVector(i,j));
        }
    }

    // Bottom left.
    for (int i = 0; i < SIZE_FOOD; i++) {
        for (int j = SIZE_H - SIZE_FOOD; j < SIZE_H; j++) {
            this->foods.push_back(PVector(i,j));
        }
    }

    // Bottom right.
    for (int i = SIZE_W - SIZE_FOOD; i < SIZE_W; i++) {
        for (int j = SIZE_H - SIZE_FOOD; j < SIZE_H; j++) {
            this->foods.push_back(PVector(i,j));
        }
    }
}

void Food::pop(int index) {
    this->foods.erase(this->foods.begin()+index);
}

void Food::draw(sf::RenderWindow *window) {

    for (auto food: foods) {
        sf::RectangleShape f_square(sf::Vector2f(1,1));
        f_square.setPosition(food.getX(), food.getY());
        f_square.setFillColor(sf::Color::Green);
        window->draw(f_square);
    }
}
