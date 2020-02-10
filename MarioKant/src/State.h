#pragma once

#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class State {
public:
	State();
	virtual ~State();

	virtual void update() = 0;
	virtual void render() = 0;

private:
	std::vector<sf::Texture> textures;
};
