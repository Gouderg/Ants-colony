#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <unistd.h>
#include <ctime>

#include "../include/colony.hpp"


int main(int argc, char const *argv[]) {	
	
	srand(time(NULL));	
	// Initialisation d'une colony
    Colony colony = Colony();


	// Initialisation de l'antialiasing et de la fenêtre
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(colony.SIZE_W,colony.SIZE_H), "Ants Colony", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {							// Attente d'évènement
			if(event.type == sf::Event::Closed) window.close();		// Fermeture de la fenêtre
		}
		// On nettoie notre écran
		window.clear(sf::Color(25,25,100,80));
		
        colony.draw(&window);
		window.display();

	}


	return 0;
}