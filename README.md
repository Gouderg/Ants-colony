# Ant Colony Optimisation

## Planning

- [X] Remplacer par un vecteur vitesse
- [X] Revoir système de rebond sur les murs

- [ ] Phéromone des fourmis
    - Tableau 2D avec des array de array 
    - Nombre de case égale au nombre WIDTH HEIGHT   
    - Algorhitme de recherche

- [ ] Wall
    - Tableau 2D de la taille de l'écran divisé par la taille des murs (Permet un positionnement parfait des murs)
    - Système de collision des fourmis.

- [ ] Food
    - Remplacer la nourriture par un tableau 2D qui se divise comme les murs avec la taille de la nourriture.



But: Trouver de la nourriture

Quand une fourmi trouve de la nourriture, elle rentre en laissant des phéromones derrières elles.
La quantité de phéromones dépends de la quantité et de la qualité de nourriture 


## Algorithm 

procedure ACO_MetaHeuristic is
    while not terminated do
        generateSolutions()
        daemonActions()
        pheromoneUpdate()
    repeat
end procedure

Nécessité d'avoir une matrice de phéromone => limité les valeurs min et max des phéromones

A chaque tour, la fourmi a la possibilité daller dans 8 directions.


## Pheromone update

$$
\begin{align}
    \tau_{xy} = (1 - p) * \tau_{xy} + \sum_{k}^{m}(\Delta\tau_{xy}^{k})
\end{align}
$$

* $\tau_{xy}$ : Amount of pheromone on deposit for a state transition xy 
* $p$ : Pheromone evaporate coefficient
* $m$ : Number of ants
* $\Delta\tau_{xy}^{k}$ : 

## Find path

    






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




## TODO

Mettre le depot de pheromone lors du retour a la base


## Bibliographie

[Optimisation par essaims paticulaires][1], Wikipedia

[How the Ant Colony Optimization algorithm works][2], Youtube, Ali Mirjalili

[Ant Colony Simulation with 5000 ants (2d).][3], Youtube, Zoom Horizon

[Ant Colony Optimization][4], Youtube, Jeff Lettman

[Ant colony Optimization Algorithms : Introduction and Beyond][5], Pdf, Anirudh Shekhawat

[Ant Colony Simulations][6], Blog, softologyblog

[Algorithme des fourmis appliqué à la détection et au suivi de contours dans une image][7], PDF, Franck GECHTER

[1]: (https://fr.wikipedia.org/wiki/Optimisation_par_essaims_particulaires)
[2]: (https://www.youtube.com/watch?v=783ZtAF4j5g)
[3]: (https://www.youtube.com/watch?v=yZ1rSASM2Rg)
[4]: (https://www.youtube.com/watch?v=xpyKmjJuqhk)
[5]: (https://mat.uab.cat/~alseda/MasterOpt/ACO_Intro.pdf)
[6]: (https://softologyblog.wordpress.com/2020/03/21/ant-colony-simulations)
[7]: (http://nicolasmonneret.free.fr/utbm/IN52/Rapport%20IN52-IN54.pdf)