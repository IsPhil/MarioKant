#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

enum buttonStates {
	BTN_IDLE = 0,
	BTN_HOVER,
	BTN_PRESSED
};

class Button {
public:
	Button(float _x, float _y, float _width, float _height, sf::Font* _font, std::string _text, sf::Color _idleColor, sf::Color _hoverColor, sf::Color _pressedColor);
	~Button();

	void update(const sf::Vector2f _mousePos);
	void render(sf::RenderTarget* _target);

	const bool isPressed() const;
	const bool isReleased() const;

private:
	unsigned short buttonState;
	unsigned short prevState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color pressedColor;		// TODO: Später unterschiedl. Sprites
};

