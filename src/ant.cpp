#include "../include/ant.hpp"

Ant::Ant(const int x_pos, const int y_pos, const int x_vel, const int y_vel) {
    this->position = PVector(x_pos, y_pos);
    this->velocity = PVector(x_vel, y_vel);
    this->isFeed = 0;
}

Ant::~Ant() {
    std::cout << "Ant destructor" << std::endl;
}


void Ant::update(Food *foods, Pheromone* phe, Wall walls) {

    // Random acceleration.
    PVector acc = PVector(rand() % 5 - 2, rand() % 5 - 2);

    // Limit acceleration.
    acc.limit(ANT_MAX_FORCE);


    // // If ants carry food.
    // if (this->isFeed == 1) {
    //     this->direction = (find_nest(phe) + 360 + rand() % 3) % 360;
    // } else {
    //     // Search pheromone trail.
    //     this->direction = (this->direction + find_pheromone_trail(phe) + 360) % 360;

    //     // Look for food.
    //     this->direction = (this->direction + find_food(foods) + 360) % 360;
    // }

    // Add acceleration to velocity.
    this->velocity.add(acc);

    // Limit velocity.
    this->velocity.limit(ANT_MAX_SPEED);

    // Add velocity to position.
    this->position.add(this->velocity);

    // Check border.
    checkBorder();

    // Check walls.
    checkWall(walls);
}


void Ant::checkBorder() {

    // X.
    if (this->position.getX() > SIZE_W) {

        this->position.setX(SIZE_W);
        this->velocity.mulX(-1);

    } else if (this->position.getX() < 0) {
        this->position.setX(0);
        this->velocity.mulX(-1);
    }

    // Y.
    if (this->position.getY() > SIZE_H) {

        this->position.setY(SIZE_H);
        this->velocity.mulY(-1);

    } else if (this->position.getY() < 0) {
        this->position.setY(0);
        this->velocity.mulY(-1);
    }

}

void Ant::checkWall(Wall walls) {

    int x = this->position.getX() * (SIZE_W / SIZE_WALL) / SIZE_W;
    int y = this->position.getY() * (SIZE_H / SIZE_WALL) / SIZE_H;

    if (walls.getWall(x, y) == 1) {
        this->velocity.mul(-1);
    }
}

int Ant::find_food(Food *foods) {

    return 0;
}

int Ant::find_nest(Pheromone* phe) {

    // If ant found the nest.
    if (this->position.getX() >= SIZE_W/2 - SIZE_COLONY && this->position.getX() <= SIZE_W/2 + SIZE_COLONY && 
        this->position.getY() >= SIZE_H/2 - SIZE_COLONY && this->position.getY() <= SIZE_H/2 + SIZE_COLONY) {
        this->isFeed = 0;
        return 180;
    }

        
    // Found angle between nest and ants.
 

    // int proba[3] = {-1, 0, 1};

    return atan2(SIZE_H/2 - this->position.getY(), SIZE_W/2 - this->position.getX()) * 180/PI;

}

int Ant::find_pheromone_trail(Pheromone* phe) {
    return 0;
}

void Ant::draw(sf::RenderWindow *window) {
    // sf::RectangleShape fourmi(sf::Vector2f(ANTS_SIZE,ANTS_SIZE));

    sf::ConvexShape fourmi;
    fourmi.setPointCount(3);
    fourmi.setPoint(0, sf::Vector2f(ANTS_SIZE, 0));
    fourmi.setPoint(1, sf::Vector2f(-ANTS_SIZE, -ANTS_SIZE/2));
    fourmi.setPoint(2, sf::Vector2f(-ANTS_SIZE, ANTS_SIZE/2));



    fourmi.setPosition(position.getX() - ANTS_SIZE/2, position.getY() - ANTS_SIZE/2);
    fourmi.setRotation(this->velocity.headings2D());
    fourmi.setFillColor(sf::Color::Yellow);
    window->draw(fourmi);
}
