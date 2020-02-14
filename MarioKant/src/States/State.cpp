#include "State.h"

State::State(sf::RenderWindow* _window) {
	this->window = _window;
	this->quit = false;
}

State::~State() {

}

void State::checkQuit() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))		// TODO: Entfernen
		this->quit = true;
}

const bool& State::getQuit() const {
	return this->quit;
}