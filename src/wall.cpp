#include "../include/wall.hpp"

Wall::Wall() {
    for (int i = 0; i < (SIZE_H / SIZE_WALL); i++) {
        for (int j = 0; j < (SIZE_W / SIZE_WALL); j++) {
            walls[i][j] = 0;
        }
    }
}

Wall::~Wall() {
    // std::cout << "Destructor Wall" << std::endl;
}

// Add wall.
void Wall::addWall(int x, int y) {

    x = x * (SIZE_W / SIZE_WALL) / SIZE_W;
    y = y * (SIZE_H / SIZE_WALL) / SIZE_H;

    this->walls[y][x] = 1;
}

void Wall::draw(sf::RenderWindow *window) {

    for (int i = 0; i < (SIZE_H / SIZE_WALL); i++) {
        for (int j = 0; j < (SIZE_W / SIZE_WALL); j++) {
            if (walls[i][j]) {
                sf::RectangleShape carre(sf::Vector2f(SIZE_WALL,SIZE_WALL));
                carre.setPosition(j * SIZE_W / (SIZE_W / SIZE_WALL), i * SIZE_H / (SIZE_H / SIZE_WALL));
                carre.setFillColor(sf::Color::Red);
                window->draw(carre);
            }
        }
    }

}