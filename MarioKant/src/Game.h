#pragma once

#include "State.h" 

class Game {
public:
	Game();
	~Game();

	void updateSFMLEvents();
	void updateDeltaTime();
	void update();
	void render();
	void run();

private:
	sf::RenderWindow *window;
	sf::Event event;
	sf::Clock dtClock;

	float dTime;					// Zeit, die für 1x updaten & 1x rendern benötigt wird in Sekunden

	void initWindow();
};