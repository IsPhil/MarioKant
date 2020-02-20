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

class Entity {
public:
	Entity();
	virtual ~Entity();

	virtual void update(const float& _dTime);
	virtual void render(sf::RenderTarget* _target);

	virtual void move(const float _dir_x, const float _dir_y, const float& _dTime);

protected:
	sf::RectangleShape shape;

	float moveSpeed;
};