#include "GameState.h"

GameState::GameState(sf::RenderWindow* _window, std::map<std::string, int>* _supportedKeys) : State(_window, _supportedKeys) {
	this->initKeybinds();
}

GameState::~GameState() {
	
}

void GameState::initKeybinds() {
	std::ifstream ifs("config/keybinds.ini");

	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2) {
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void GameState::updateInput(const float& _dTime) {
	this->checkQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player.move(-1.f, 0.f, _dTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player.move(1.f, 0.f, _dTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player.move(0.f, -1.f, _dTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player.move(0.f, 1.f, _dTime);
}

void GameState::update(const float& _dTime) {
	this->updateInput(_dTime);
	this->player.update(_dTime);
}

void GameState::render(sf::RenderTarget* _target) {
	if (!_target)
		_target = this->window;
	
	this->player.render(_target);
}

void GameState::endState() {
	std::cout << "Ending tis bs." << std::endl;
}
