#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <string> 

#include "../include/colony.hpp"
#include "../include/wall.hpp"
#include "../include/ant.hpp"
#include "../include/food.hpp"


int main(int argc, char const *argv[]) {	

	srand(time(NULL));	
	sf::Clock clock;

	// Colony initialization.
    Colony colony = Colony();

	// Barrier initilization.
	Wall wall = Wall();

	// Food initialisation.
	Food foods = Food();


	// Initialisation de l'antialiasing et de la fenêtre.
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(SIZE_W,SIZE_H), "Ants Colony", sf::Style::Default, settings);
	window.setFramerateLimit(0);

	// Initialisation affichage fps.
	sf::Font font;
	// Load it from a file.
	if (!font.loadFromFile("font/Poppins-Bold.ttf")) {
		std::cout << "Failed to load font" << std::endl;
	}
	sf::Text fps;
	fps.setFont(font);
	fps.setString("FPS: ");
	fps.setFillColor(sf::Color::White);
	fps.setCharacterSize(24);
	int count = 0;

	// Main loop.
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {							// Wait event.
			if(event.type == sf::Event::Closed) window.close();		// Close window.
		}
		
		// Clean screen.
		window.clear(sf::Color(25,25,100,80));

		// Add wall.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			sf::Vector2i pos = sf::Mouse::getPosition(window);
			wall.addWall(pos.x, pos.y);
		}

		// Add food.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			sf::Vector2i pos = sf::Mouse::getPosition(window);
			foods.add(pos.x, pos.y);
		}
		// Update colony.
		colony.update(&foods, wall);

		// Display FPS.
        count += 1;
		sf::Time frameTime = clock.getElapsedTime();
		if (frameTime.asSeconds() >= 1) {
			fps.setString("FPS: "+ std::to_string(count));
			clock.restart();
			count = 0;
		}
		
		// Draw all.
		wall.draw(&window);
		foods.draw(&window);
        colony.draw(&window);
		window.draw(fps);
		
		window.display();
	}


	return 0;
}