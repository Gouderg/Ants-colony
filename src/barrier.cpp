#include "../include/barrier.hpp"

Barrier::Barrier(const int x, const int y) {
    PVector *pos = new PVector(x,y);
    this->barrier.push_back(pos);
}

Barrier::~Barrier() {
    std::cout << "Desctructor barrier" << std::endl;
}

void Barrier::draw(sf::RenderWindow *window) {
    for (auto elt : barrier) {
        sf::RectangleShape carre(sf::Vector2f(1,1));
        carre.setPosition(elt->getX(), elt->getY());
        carre.setFillColor(sf::Color::Green);
        window->draw(carre);
    }   
}