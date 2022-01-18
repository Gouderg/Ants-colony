#include "../include/ant.hpp"

Ant::Ant(const int x, const int y, const int vx, const int vy) {
    this->velocity = PVector(vx, vy);
    this->position = PVector(x, y);
    this->isFeed = 0;
}

Ant::~Ant() {
    std::cout << "Ant destructor" << std::endl;
}


void Ant::update() {

    // Add velocity to position.
    this->position.add(this->velocity);

    // Check border.
    checkBorder();
}


int Ant::checkBorder() {

    // Border right.
    if (this->position.getX() + ANTS_SIZE_W/2 >= SIZE_W) {
        this->velocity.setX(this->velocity.getX() * - 1);
    }

    // Border down.
    if (this->position.getY() + ANTS_SIZE_H/2 >= SIZE_H) {
        this->velocity.setY(this->velocity.getY() * - 1);
    }

    // Border left.
    if (this->position.getX() - ANTS_SIZE_W/2 < 0) {
        this->velocity.setX(this->velocity.getX() * - 1);
    }

    // Border up.
    if (this->position.getY() - ANTS_SIZE_H/2 < 0) {
        this->velocity.setY(this->velocity.getY() * - 1);
    }


    return 1;
}

void Ant::draw(sf::RenderWindow *window) {
    sf::RectangleShape fourmi(sf::Vector2f(ANTS_SIZE_W,ANTS_SIZE_H));
    fourmi.setPosition(position.getX() - ANTS_SIZE_W/2, position.getY() - ANTS_SIZE_H/2);
    fourmi.setFillColor(sf::Color::Red);
    window->draw(fourmi);
}
