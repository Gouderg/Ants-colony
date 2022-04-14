# Ant Colony Optimisation

## Planning

- [ ] Phéromone des fourmis
- [ ] Remplacer par un vecteur vitesse
- [ ] Revoir système de rebond sur les murs
- [ ] Mise en place des murs à des coordonnées fixe (Grille)


But: Trouver de la nourriture

Quand une fourmi trouve de la nourriture, elle rentre en laissant des phéromones derrières elles.
La quantité de phéromones dépends de la quantité et de la qualité de nourriture 

https://www.youtube.com/watch?v=783ZtAF4j5g
https://www.youtube.com/watch?v=yZ1rSASM2Rg
https://www.youtube.com/watch?v=xpyKmjJuqhk
https://mat.uab.cat/~alseda/MasterOpt/ACO_Intro.pdf

https://softologyblog.wordpress.com/2020/03/21/ant-colony-simulations
http://nicolasmonneret.free.fr/utbm/IN52/Rapport%20IN52-IN54.pdf

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


### Mettre en place un système de hitbox


### Algo

Vitesse des fourmis => (7, 7) => area 2,2

Sélectionner les directions 8 (diagonales) puis appliquer la formule de proba pour trouver le chemin

