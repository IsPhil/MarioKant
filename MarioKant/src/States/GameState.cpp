#include "GameState.h"

GameState::GameState(sf::RenderWindow* _window) : State(_window) {

}

GameState::~GameState() {
	
}

void GameState::updateKeybinds(const float& _dTime) {
	this->checkQuit();
}

void GameState::update(const float& _dTime) {
	this->updateKeybinds(_dTime);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "A";
}

void GameState::render(sf::RenderTarget* _target) {

}

void GameState::endState() {
	std::cout << "Ending tis bs." << std::endl;
}
