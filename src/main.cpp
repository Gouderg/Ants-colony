#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <unistd.h>
#include <ctime>

#include "../include/colony.hpp"
#include "../include/barrier.hpp"
#include "../include/ant.hpp"


int main(int argc, char const *argv[]) {	
	
	srand(time(NULL));	

	// Colony initialization.
    Colony colony = Colony();

	// Barrier initilization
	// Barrier barrier = Barrier();


	// Ants test.
	Ant ant = Ant(SIZE_W / 2, SIZE_H / 2);

	// Initialisation de l'antialiasing et de la fenêtre
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(SIZE_W,SIZE_H), "Ants Colony", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {							// Wait event.
			if(event.type == sf::Event::Closed) window.close();		// Close window.
		}
		
		// Add wall.
		// if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		// 	sf::Vector2i pos = sf::Mouse::getPosition(window);
		// 	barrier.addWall(pos.x, pos.y);
		// }
		

		// Clean screen.
		window.clear(sf::Color(25,25,100,80));
		
		ant.update();
		ant.draw(&window);
		// barrier.draw(&window);
        // colony.draw(&window);


		window.display();

	}


	return 0;
}