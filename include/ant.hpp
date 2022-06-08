#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "constante.hpp"
#include "pvector.hpp"
#include "food.hpp"
#include "pheromone.hpp"
#include "wall.hpp"

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
        void update(Food *foods, Pheromone* phe_global, Wall walls, Pheromone* phe_tour, Pheromone* phe_nb_ants);

        void checkBorder();
        void checkWall(Wall walls);
        int find_pheromone_trail(Pheromone* phe);
        void find_food(Food *foods);
        PVector find_nest(Pheromone* phe_tour, Pheromone* phe_nb_ants);
        PVector seek(PVector target);  // Follow a target.

    
    private:

        PVector position;     // Position.
        PVector velocity;     // Velocity.
        int sense_angle;      // Sense angle.
        int sense_direction;  // Sense direction. 
        bool isFeed;           // With or Without feed. 
};  