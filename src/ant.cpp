#include "../include/ant.hpp"

Ant::Ant(const int x, const int y, const int direction, const int speed) {
    this->direction = direction;
    this->speed = speed;
    this->position = PVector(x, y);
    this->isFeed = 0;
}

Ant::~Ant() {
    std::cout << "Ant destructor" << std::endl;
}


void Ant::update() {

    // Search pheromone trail.
    this->direction = (this->direction + find_pheromone_trail()) % 360;

    // Add velocity to position.
    PVector velocity = PVector::velocity(this->direction, this->speed);
    this->position.add(velocity);

    // Check border.
    checkBorder();
}


void Ant::checkBorder() {

    int turn = 0;

    // Border right.
    if (this->position.getX() + ANTS_SIZE_W/2 >= SIZE_W) {
        turn = (this->direction < 180) ? 90 : -90;
    }

    // Border down.
    if (this->position.getY() + ANTS_SIZE_H/2 >= SIZE_H) {
        turn = (this->direction > 270) ? 90 : -90;
    }

    // Border left.
    if (this->position.getX() - ANTS_SIZE_W/2 < 0) {
        turn = (this->direction > 180) ? 90 : -90;
    }

    // Border up.
    if (this->position.getY() - ANTS_SIZE_H/2 < 0) {
        turn = (this->direction < 90) ? 90 : -90;
    }
    
    this->direction = (this->direction + turn) % 360;

}

int Ant::find_pheromone_trail() {
    
    // Ahead.
    PVector ahead = PVector::add(this->position, PVector::velocity(0, SENSE_DISTANCE));
    
    // Left.
    PVector left = PVector::add(this->position, PVector::velocity((this->direction - SENSE_ANGLE) % 360, SENSE_DISTANCE));
    
    // Right.
    PVector right = PVector::add(this->position, PVector::velocity((this->direction + SENSE_ANGLE) % 360, SENSE_DISTANCE));

    int proba[4] = {-SENSE_ANGLE, 0, 0, SENSE_ANGLE};

    return proba[rand() % 4];

}

void Ant::draw(sf::RenderWindow *window) {
    sf::RectangleShape fourmi(sf::Vector2f(ANTS_SIZE_W,ANTS_SIZE_H));
    fourmi.setPosition(position.getX() - ANTS_SIZE_W/2, position.getY() - ANTS_SIZE_H/2);
    fourmi.setFillColor(sf::Color::Yellow);
    window->draw(fourmi);
}
