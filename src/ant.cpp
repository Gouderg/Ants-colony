#include "../include/ant.hpp"

Ant::Ant(const int x, const int y) {
    this->velocity = PVector(0,0);
    this->position = PVector(x, y);
    this->isFeed = 0;
}

Ant::~Ant() {
    std::cout << "Ant destructor" << std::endl;
}

void Ant::draw(sf::RenderWindow *window) {
    sf::RectangleShape fourmi(sf::Vector2f(getSizeW(),getSizeH()));
    fourmi.setPosition(position.getX(), position.getY());
    fourmi.setFillColor(sf::Color::Red);
    window->draw(fourmi);
}
