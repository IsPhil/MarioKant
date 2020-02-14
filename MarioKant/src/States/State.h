#pragma once

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <vector>				// TODO: Eigene Vector-Klasse

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class State {
public:
	State(sf::RenderWindow* _window);
	virtual ~State();

	virtual void updateKeybinds(const float& _dTime) = 0;
	virtual void update(const float& _dTime) = 0;
	virtual void render(sf::RenderTarget* _target = nullptr) = 0;
	
	virtual void endState() = 0;
	virtual void checkQuit();
	

	const bool& getQuit() const;

private:
	bool quit;

	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
};
