#include "State.h"

State::State(sf::RenderWindow* _window, std::map<std::string, int>* _supportedKeys) {
	this->window = _window;
	this->supportedKeys = _supportedKeys;
	this->quit = false;
}

State::~State() {

}

void State::updateMousePos() {
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void State::checkQuit() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("PAUSE"))))		// TODO: Nur Debug. Entfernen
		this->quit = true;
}

const bool& State::getQuit() const {
	return this->quit;
}