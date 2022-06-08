#include "../include/ant.hpp"

Ant::Ant(const int x_pos, const int y_pos, const int x_vel, const int y_vel) {
    this->position = PVector(x_pos, y_pos);
    this->velocity = PVector(x_vel, y_vel);
    this->isFeed = 0;
}

Ant::~Ant() {
    std::cout << "Ant destructor" << std::endl;
}


void Ant::update(Food *foods, Pheromone* phe_global, Wall walls, Pheromone* phe_tour, Pheromone* phe_nb_ants) {


    // Random acceleration.
    PVector acc = PVector(rand() % 5 - 2, rand() % 5 - 2);

    // If ants carry food.
    if (this->isFeed == 1) {
        
         acc = find_nest(phe_tour, phe_nb_ants);

    } else {
        // Search pheromone trail.
        // this->direction = (this->direction + find_pheromone_trail(phe) + 360) % 360;
        // Check for food.
        find_food(foods);
    }

    // Limit acceleration.
    acc.limit(ANT_MAX_FORCE);

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

void Ant::find_food(Food *foods) {

    int x = this->position.getX() * (SIZE_W / SIZE_FOOD_PIXEL) / SIZE_W;
    int y = this->position.getY() * (SIZE_H / SIZE_FOOD_PIXEL) / SIZE_H;

    // If ant found food.
    if (foods->getFood(x, y) == 1) { 
        foods->setFood(x, y);   // Remove food.
        this->isFeed = 1;
        PVector::rotate2D(this->position, 180);
    }


}

PVector Ant::find_nest(Pheromone* phe_tour, Pheromone* phe_nb_ants) {

    // If ant found the nest.
    if (this->position.getX() >= SIZE_W/2 - SIZE_COLONY && this->position.getX() <= SIZE_W/2 + SIZE_COLONY && 
        this->position.getY() >= SIZE_H/2 - SIZE_COLONY && this->position.getY() <= SIZE_H/2 + SIZE_COLONY) {
        this->isFeed = 0;
        PVector::rotate2D(this->position, 180);
        return PVector(0,0);
    }

    // Depose an amout of pheromone.
    phe_nb_ants->addPheromone(this->position.getX(), this->position.getY(), 1);
    phe_tour->addPheromone(this->position.getX(), this->position.getY(), PHE_INCREASE);


    return seek(PVector(SIZE_W/2, SIZE_H/2));
    
    // return atan2(SIZE_H/2 - this->position.getY(), SIZE_W/2 - this->position.getX()) * 180/M_PI;

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
    if (this->isFeed) {
        fourmi.setFillColor(sf::Color::Magenta);
    } else {
        fourmi.setFillColor(sf::Color::Yellow);
    }
    window->draw(fourmi);
}

PVector Ant::seek(PVector target) {
    PVector force = PVector::sub(target, this->position);

    force.setMag(ANT_MAX_SPEED);
    force.sub(this->velocity);
    force.limit(ANT_MAX_FORCE);
    return force;
}