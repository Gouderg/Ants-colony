#include "../include/ant.hpp"

Ant::Ant(const int x, const int y) {
    this->velocity = PVector(1,1);
    this->position = PVector(x, y);
    this->isFeed = 0;
}

Ant::~Ant() {
    std::cout << "Ant destructor" << std::endl;
}


void Ant::update() {

    // Add velocity to position.
    this->position.add(this->velocity);

    // Check bordure
}


int Ant::checkBorder() {

    if (this->position.getX() + getSizeW() >= SIZE_W) {
        std::cout << "Sortie bord droit" << std::endl;
    }

    if (this->position.getY() + getSizeH() >= SIZE_H) {
        std::cout << "Sortie bord bas" << std::endl;
    }


    return 1;
}

void Ant::draw(sf::RenderWindow *window) {
    sf::RectangleShape fourmi(sf::Vector2f(getSizeW(),getSizeH()));
    fourmi.setPosition(position.getX() - getSizeW()/2, position.getY() - getSizeH()/2);
    fourmi.setFillColor(sf::Color::Red);
    window->draw(fourmi);
}
