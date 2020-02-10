#pragma once

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game {
public:
	Game();
	~Game();

	void updateSFMLEvents();
	void update();
	void render();
	void run();

private:
	sf::RenderWindow *window;
	sf::Event event;

	const char* TITLE = "Ass Link"; //Ass Link

	void initWindow();
};