#pragma once

// Size of the screen.
const int SIZE_W = 1200;
const int SIZE_H = 1000;              

// Ants information.    
const int ANTS_SIZE = 2;                     // Ants size.
const int SENSE_ANGLE = 15;                  // Angle of maximun rotation.
const int SENSE_DISTANCE = 5;                // Distance of maximum detection.
const int ANT_MAX_SPEED = 2;                 // Max speed for ants.
const double ANT_MAX_FORCE = 0.5;               // Max ants force apply.

// Information about the colony.
const int NB_ANTS_CREATION = 60;             // Nb ants in first frame.
const int NB_ANTS = 100;                     // Total number of ants.
const int SIZE_COLONY = 5;                   // Size of the circle represented the colony.
const int OUT_SIZE_COLONY = 2;               // Size of the outline circle.

// Size of Wall.
const int SIZE_WALL = 20;                     // Size of a wall.

// Food information.
const int NB_FOOD = 20;                      // Nb food in a square.
const int SIZE_FOOD_PIXEL = 5;               // Size of a pixel food.

// Pheromone information.
const int PHE_DIFFUSION = 3;                 // Size of the champ.        
const int PHE_MAX = 255;
const int PHE_INCREASE = 50;
const int PHE_DECREASE = 1; 
const int PHE_INIT = 10;
const double PHE_EVAPORATION_COEFFICIENT = 0.01;