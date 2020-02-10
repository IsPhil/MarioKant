#include "Game.h"

Game::Game() {
	this->initWindow();
}

Game::~Game() {
	delete this->window;
}


void Game::initWindow() {

	unsigned fps_limit = 60;
	bool vsync_enabled = false;
	
	sf::VideoMode window_bounds(1280, 720);
	std::ifstream ifs("../config/window.ini");
	std::string title = "None";

	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fps_limit;
		ifs >> vsync_enabled;
	}

	ifs.close();

	//this->window = new sf::RenderWindow(sf::VideoMode().getDesktopMode(), this->TITLE, sf::Style::Fullscreen);
	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(fps_limit);
	this->window->setVerticalSyncEnabled(vsync_enabled);
}

void Game::updateSFMLEvents() {
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed)
			window->close();
	}
}

void Game::updateDeltaTime() {
	this->dTime = this->dtClock.restart().asSeconds();
}

void Game::update() {
	this->updateSFMLEvents();
}

void Game::render() {
	this->window->clear();

	// Render

	this->window->display();
}

void Game::run() {
	while (this->window->isOpen()) {
		this->updateDeltaTime();
		this->update();
		this->render();
	}
}
