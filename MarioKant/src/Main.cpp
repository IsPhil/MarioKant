#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Ass Link"); //Ass Link
	sf::Font font;
	
	if (!font.loadFromFile("res/fonts/dacasa.ttf")) {
		std::cout << "Fuck" << std::endl;
		return -1;
	}
	
	sf::Text text("Ass Link", font, 40U);
	text.setStyle(sf::Text::Bold);

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(text);
		window.display();
	}
	
	return 0;
}