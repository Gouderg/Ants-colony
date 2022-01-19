#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "constante.hpp"
#include "pvector.hpp"
#include "food.hpp"

class Ant {
    public:
        
        // Constructor.
        Ant(const int x, const int y, const int direction, const int speed);

        // Destructor.
        ~Ant();

        // Getter.
        int getDirection() const {return this->direction;}
        int getSpeed() const {return this->speed;}
        int getSenseDirection() const {return this->sense_direction;}
        int getSenseAngle() const {return this->sense_angle;}
        PVector getPosition() const {return this->position;}

        // Setter.
        void setDirection(const int direction) {this->direction = direction;}
        void setSpeed(const int speed) {this->speed = speed;}
        void setSenseDirection(const int direction) {this->sense_direction = direction;}
        void setSenseAngle(const int angle) {this->sense_angle = angle;}

        // Other.
        void draw(sf::RenderWindow *window);
        void update(Food *foods);
        void checkBorder();
        int find_pheromone_trail();
        int find_food(Food *foods);
        int find_nest();

    
    private:
        static const int max_angle = 180;

        PVector position;     // Position.
        int direction;        // Direction.
        int speed;            // Speed.
        int sense_angle;      // Sense angle.
        int sense_direction;  // Sense direction. 
        bool isFeed;           // With or Without feed. 
};  