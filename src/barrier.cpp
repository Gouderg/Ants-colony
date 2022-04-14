#include "../include/barrier.hpp"

Barrier::Barrier() {

}

Barrier::~Barrier() {
    // std::cout << "Destructor barrier" << std::endl;
}

// Add wall.
void Barrier::addWall(const int x, const int y) {
    bool isHere = false;
    for (auto elt : this->barrier) {
        if (x > elt->getPos().getX() - SIZE_WALL && x < elt->getPos().getX() + SIZE_WALL && y > elt->getPos().getY() - SIZE_WALL && y < elt->getPos().getY() + SIZE_WALL) {
            
            std::cout << "Hello" << std::endl;
            isHere = true;
            break;
        }
    }
    if (!isHere) {
        Wall* wall = new Wall(x, y);
        this->barrier.push_back(wall);
    }

}

void Barrier::draw(sf::RenderWindow *window) {
    for (auto elt : getBarrier()) {
        PVector pos = elt->getPos();

        sf::RectangleShape carre(sf::Vector2f(SIZE_WALL,SIZE_WALL));
        carre.setPosition(pos.getX() - SIZE_WALL/2, pos.getY() - SIZE_WALL/2);
        carre.setFillColor(sf::Color::Green);
        window->draw(carre);
    }   
}