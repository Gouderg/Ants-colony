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


void Ant::update(Food *foods, std::vector<Pheromone*> *phe) {

    // If ants carry food.
    if (this->isFeed == 1) {
        this->direction = (find_nest(phe) + 360 + rand() % 3) % 360;
    } else {
        // Search pheromone trail.
        this->direction = (this->direction + find_pheromone_trail(phe) + 360) % 360;

        // Look for food.
        this->direction = (this->direction + find_food(foods) + 360) % 360;
    }


    // Add velocity to position.
    PVector velocity = PVector::velocity(this->direction, this->speed);
    this->angle = velocity.headings2D();
    this->position.add(velocity);

    // Check border.
    checkBorder();
}


void Ant::checkBorder() {

    int turn = 0;

    // Border right.
    if (this->position.getX() + ANTS_SIZE/2 >= SIZE_W) {
        turn = (this->direction < 180) ? 90 : -90;
    }

    // Border down.
    if (this->position.getY() + ANTS_SIZE/2 >= SIZE_H) {
        turn = (this->direction > 270) ? 90 : -90;
    }

    // Border left.
    if (this->position.getX() - ANTS_SIZE/2 < 0) {
        turn = (this->direction > 180) ? 90 : -90;
    }

    // Border up.
    if (this->position.getY() - ANTS_SIZE/2 < 0) {
        turn = (this->direction < 90) ? 90 : -90;
    }
    
    this->direction = (this->direction + turn + 360) % 360;

}

int Ant::find_food(Food *foods) {

    // If ant found the food.
    PVector pos = PVector((int) this->position.getX(), (int) this->position.getY());
    std::vector<PVector> test = foods->getFood();
    for (int i = 0; i < test.size(); i++) {
        if (PVector::equal_for_food(pos, test[i])) {
            foods->pop(i);
            this->isFeed = 1;
            return 180;
        }
    }

    return 0;
}

int Ant::find_nest(std::vector<Pheromone*> *phe) {

    // If ant found the nest.
    if (this->position.getX() >= SIZE_W/2 - SIZE_COLONY && this->position.getX() <= SIZE_W/2 + SIZE_COLONY && 
        this->position.getY() >= SIZE_H/2 - SIZE_COLONY && this->position.getY() <= SIZE_H/2 + SIZE_COLONY) {
        this->isFeed = 0;
        return 180;
    }

    // Add pheromone.
    bool isNotIn = true;
    // S'il est deja dedans, on ajoute un depot de 10
    for (int i = 0; i < (*phe).size(); i++) {
        if ((int) (*phe)[i]->getPosition().getX() == (int) this->position.getX() && (int) (*phe)[i]->getPosition().getY() == (int) this->position.getY()) {
            int dep = (*phe)[i]->getDepot();
            if (dep + 10 > 255) {
                (*phe)[i]->setDepot(PHE_MAX);
            } else {
                (*phe)[i]->setDepot(dep + PHE_INCREASE);
            }
            isNotIn = false;
            break;
        }
    }
    // Sinon on le crée
    if (isNotIn) {
        PVector p = PVector(this->position.getX(), this->position.getY());
        (*phe).push_back(new Pheromone(p, PHE_INIT));
    }

    
    
    // Found angle between nest and ants.
 

    // int proba[3] = {-1, 0, 1};

    return atan2(SIZE_H/2 - this->position.getY(), SIZE_W/2 - this->position.getX()) * 180/PI;

}

int Ant::find_pheromone_trail(std::vector<Pheromone*> *phe) {
    
    // Ahead.
    PVector ahead = PVector::add(this->position, PVector::velocity(0, SENSE_DISTANCE));
    
    // Left.
    PVector left = PVector::add(this->position, PVector::velocity((this->direction - SENSE_ANGLE) % 360, SENSE_DISTANCE));
    
    // Right.
    PVector right = PVector::add(this->position, PVector::velocity((this->direction + SENSE_ANGLE) % 360, SENSE_DISTANCE));

    int x = 0;
    int y = 0;
    for (int i = 0; i < (*phe).size(); i++) {
        x = (*phe)[i]->getPosition().getX();
        y = (*phe)[i]->getPosition().getY();

        if (x == (int) ahead.getX() && y == (int) ahead.getY()) {
            return 0;
        }

        if (x == (int) left.getX() && y == (int) left.getY()) {
            return SENSE_ANGLE;
        }

        if (x == (int) right.getX() && y == (int) right.getY()) {
            return -SENSE_ANGLE;
        }
    }

    int proba[4] = {-SENSE_ANGLE, 0, 0, SENSE_ANGLE};

    return proba[rand() % 4];

}

void Ant::draw(sf::RenderWindow *window) {
    // sf::RectangleShape fourmi(sf::Vector2f(ANTS_SIZE,ANTS_SIZE));

    sf::ConvexShape fourmi;
    fourmi.setPointCount(3);
    fourmi.setPoint(0, sf::Vector2f(ANTS_SIZE, 0));
    fourmi.setPoint(1, sf::Vector2f(-ANTS_SIZE, -ANTS_SIZE/2));
    fourmi.setPoint(2, sf::Vector2f(-ANTS_SIZE, ANTS_SIZE/2));



    fourmi.setPosition(position.getX() - ANTS_SIZE/2, position.getY() - ANTS_SIZE/2);
    fourmi.setRotation(this->angle);
    fourmi.setFillColor(sf::Color::Yellow);
    window->draw(fourmi);
}
