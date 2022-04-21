#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "constante.hpp"
#include "pvector.hpp"
#include "food.hpp"
#include "pheromone.hpp"

class Ant {
    public:
        
        // Constructor.
        Ant(const int x_pos, const int y_pos, const int x_vel, const int y_vel);

        // Destructor.
        ~Ant();

        // Getter.
        int getSenseDirection() const {return this->sense_direction;}
        int getSenseAngle() const {return this->sense_angle;}
        int getIsFeed() const {return this->isFeed;}
        PVector getPosition() const {return this->position;}


        // Setter.
        void setSenseDirection(const int direction) {this->sense_direction = direction;}
        void setSenseAngle(const int angle) {this->sense_angle = angle;}

        // Other.
        void draw(sf::RenderWindow *window);
        void update(Food *foods, std::vector<Pheromone*> *phe);
        void checkBorder();
        int find_pheromone_trail(std::vector<Pheromone*> *phe);
        int find_food(Food *foods);
        int find_nest(std::vector<Pheromone*> *phe);

    
    private:
        static const int max_angle = 180;

        PVector position;     // Position.
        PVector velocity;     // Velocity.
        double angle;         // Which direction to see.
        int sense_angle;      // Sense angle.
        int sense_direction;  // Sense direction. 
        bool isFeed;           // With or Without feed. 
};  