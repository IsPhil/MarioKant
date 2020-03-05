#pragma once

#include "GameState.h"
#include "../UI/Button.h"

class MainMenuState : public State {
public:
	MainMenuState(sf::RenderWindow* _window, std::map<std::string, int>* _supportedKeys);
	virtual ~MainMenuState();

	void updateInput(const float& _dTime);
	void updateButtons();
	void update(const float& _dTime);
	void renderButtons(sf::RenderTarget* _target = nullptr);
	void render(sf::RenderTarget* _target = nullptr);

	void endState();

private: 
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, Button*> buttons;

	void initFonts();
	void initKeybinds();
	void initButtons();
};