#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
	int WIDTH = 1280;
	int HEIGHT = WIDTH / 16 * 9;
	const char* TITLE = "Ass Link"; //Ass Link
	
	sf::RenderWindow window(sf::VideoMode().getDesktopMode(), TITLE, sf::Style::Fullscreen);
	
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}
	
	return 0;
}