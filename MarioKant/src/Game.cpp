#include "Game.h"

Game::Game() {
	this->initWindow();
}

Game::~Game() {
	delete this->window;
}


void Game::initWindow() {
	this->window = new sf::RenderWindow(sf::VideoMode().getDesktopMode(), this->TITLE, sf::Style::Fullscreen);
}

void Game::updateSFMLEvents() {
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed)
			window->close();
	}
}

void Game::update() {
	this->updateSFMLEvents();
}

void Game::render() {
	this->window->clear();



	this->window->display();
}

void Game::run() {
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
}
