#include "../include/food.hpp"


Food::Food() {
    // Init to 0.
    for (int i = 0; i < SIZE_H / SIZE_FOOD_PIXEL; i += 1) {
        for (int j = 0; j < SIZE_W / SIZE_FOOD_PIXEL; j += 1) {
            this->foods[i][j] = 0;
        }
    }

    // Place square in each corner.
    
    // Top left.
    for (int i = 0; i < NB_FOOD; i += 1) {
        for (int j = 0; j < NB_FOOD; j += 1) {
            this->foods[i][j] = 1;
        }
    }

    // Top right.
    for (int i = SIZE_H / SIZE_FOOD_PIXEL - NB_FOOD; i < SIZE_H / SIZE_FOOD_PIXEL; i += 1) {
        for (int j = 0; j < NB_FOOD; j += 1) {
            this->foods[i][j] = 1;

        }
    }

    // Bottom left.
    for (int i = 0; i < NB_FOOD; i += 1) {
        for (int j = SIZE_W / SIZE_FOOD_PIXEL - NB_FOOD; j < SIZE_W / SIZE_FOOD_PIXEL; j += 1) {
            this->foods[i][j] = 1;
        }
    }

    // Bottom right.
    for (int i = SIZE_H / SIZE_FOOD_PIXEL - NB_FOOD; i < SIZE_H / SIZE_FOOD_PIXEL; i += 1) {
        for (int j = SIZE_W / SIZE_FOOD_PIXEL - NB_FOOD; j < SIZE_W / SIZE_FOOD_PIXEL; j += 1) {
            this->foods[i][j] = 1;
        }
    }
}

// Add food.
void Food::add(int x, int y) {

    x = x * (SIZE_W / SIZE_FOOD_PIXEL) / SIZE_W;
    y = y * (SIZE_H / SIZE_FOOD_PIXEL) / SIZE_H;

    this->foods[y][x] = 1;
}

void Food::draw(sf::RenderWindow *window) {

    for (int i = 0; i < SIZE_H / SIZE_FOOD_PIXEL; i++) {
        for (int j = 0; j < SIZE_W / SIZE_FOOD_PIXEL; j++) {
            if (this->foods[i][j]) {
                sf::RectangleShape f_square(sf::Vector2f(SIZE_FOOD_PIXEL, SIZE_FOOD_PIXEL));
                f_square.setPosition(j * SIZE_W / (SIZE_W / SIZE_FOOD_PIXEL), i * SIZE_H / (SIZE_H / SIZE_FOOD_PIXEL));
                f_square.setFillColor(sf::Color::Green);
                window->draw(f_square);
            }
        }
    }
}
