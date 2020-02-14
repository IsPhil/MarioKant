#pragma once

#include "State.h"

class GameState : public State {
public:
	GameState(sf::RenderWindow* _window);
	virtual ~GameState();

	void updateKeybinds(const float& _dTime);
	void update(const float& _dTime);
	void render(sf::RenderTarget* _target = nullptr);

	void endState();

private:

};
