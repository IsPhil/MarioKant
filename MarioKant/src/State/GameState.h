#pragma once

#include "State.h"

class GameState : public State {
public:
	GameState(sf::RenderWindow* _window, std::map<std::string, int>* _supportedKeys);
	virtual ~GameState();

	void updateInput(const float& _dTime);
	void update(const float& _dTime);
	void render(sf::RenderTarget* _target = nullptr);

	void endState();

private:
	Entity player;

	void initKeybinds();
};