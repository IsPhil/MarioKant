 #pragma once

#include "State/MainMenuState.h"

class Game {
public:
	Game();
	~Game();

	void endProgram();

	void updateSFMLEvents();
	void updateDeltaTime();
	void update();
	
	void render();

	void run();

private:
	sf::RenderWindow *window;
	sf::Event event;
	sf::Clock dtClock;

	std::stack<State*> states;
	std::map<std::string, int> supportedKeys;

	float dTime;					// Zeit, die für 1x updaten & 1x rendern benötigt wird in Sekunden

	void initWindow();
	void initKeys();
	void initStates();
};