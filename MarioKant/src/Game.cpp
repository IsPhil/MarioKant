#include "Game.h"

Game::Game() {
	this->initWindow();
	this->initKeys();
	this->initStates();
}

Game::~Game() {
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();		// Entfernt Daten vom Pointer
		this->states.pop();				// Entfernt den Pointer
	}
}

//-Init-Bois-----------------------------------------------------------------------------

void Game::initWindow() {

	unsigned fps_limit = 60;
	bool vsync_enabled = false;
	
	sf::VideoMode window_bounds(1280, 720);
	std::string title = "None";
	std::string screen_mode = "WINDOWED";
	std::ifstream ifs("config/window.ini");
	
	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fps_limit;
		ifs >> vsync_enabled;
		ifs >> screen_mode;
	}

	ifs.close();

	if (screen_mode == (std::string)"FULLSCREEN")
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen);
	else if (screen_mode == (std::string)"WINDOWED")
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Default);
	else
		this->window = new sf::RenderWindow(window_bounds, title);
	
	this->window->setFramerateLimit(fps_limit);
	this->window->setVerticalSyncEnabled(vsync_enabled);
}

void Game::initKeys() {
	std::ifstream ifs("config/keys.ini");

	if (ifs.is_open()) {
		std::string key = "";
		int key_val = 0;

		while (ifs >> key >> key_val) {
			this->supportedKeys[key] = key_val;
		}
	}

	ifs.close();
	
	for (auto i : this->supportedKeys)
		std::cout << i.first << " " << i.second << std::endl;
}

void Game::initStates() {
	this->states.push(new MainMenuState(this->window, &this->supportedKeys));
}

//-Other-Bois----------------------------------------------------------------------------

void Game::endProgram() {
	std::cout << "Exiting Game..." << std::endl;
}

void Game::updateSFMLEvents() {
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::updateDeltaTime() {
	this->dTime = this->dtClock.restart().asSeconds();
}

void Game::update() {
	this->updateSFMLEvents();

	if (!this->states.empty()) {
		this->states.top()->update(this->dTime);
	
		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	} else {
		this->endProgram();
		this->window->close();
	}
}

void Game::render() {
	this->window->clear();

	// Render shit here
	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();
}



void Game::run() {
	std::cout << "Using SFML-Version 2.5.1" << std::endl;
	std::cout << "Starting Game..." << std::endl;
	std::cout << "------------------------------------------------------------------" << std::endl;

	while (this->window->isOpen()) {
		this->updateDeltaTime();
		this->update();
		this->render();
	}
}
