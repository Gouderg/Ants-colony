# Ant Colony Optimisation

But: Trouver de la nourriture

Quand une fourmi trouve de la nourriture, elle rentre en laissant des phéromones derrières elles.
La quantité de phéromones dépends de la quantité et de la qualité de nourriture 

https://www.youtube.com/watch?v=783ZtAF4j5g
https://www.youtube.com/watch?v=yZ1rSASM2Rg

https://mat.uab.cat/~alseda/MasterOpt/ACO_Intro.pdf

## Algorithm 

procedure ACO_MetaHeuristic is
    while not terminated do
        generateSolutions()
        daemonActions()
        pheromoneUpdate()
    repeat
end procedure

Nécessité d'avoir une matrice de phéromone => limité les valeurs min et max des phéromones


## Pheromone update


Txy = (1 - p) + Txy + Somme(m->k) pow(delta Txy, k)
Txy: Amount of pheromone on deposit for a state transition xy
p: Pheromone evaporate coefficient
m: Number of ants
pow(delta Txy, k): 



## Décomposition des classes
Une classe colony
Une classe ant
Une classe food
Une class obstacle

## Colors

Green: food
White: Ants
Blue: Pheromone without food
Red: Pheromone with food

## Variable global
Nombre de fourmi
Min phéromone
Max phéromone
