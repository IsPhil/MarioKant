#pragma once

#include "../Entity/Entity.h"

class State {
public:
	State(sf::RenderWindow* _window, std::map<std::string, int>* _supportedKeys);
	virtual ~State();

	virtual void updateInput(const float& _dTime) = 0;
	virtual void update(const float& _dTime) = 0;
	virtual void render(sf::RenderTarget* _target = nullptr) = 0; 
	
	virtual void endState() = 0;
	virtual void checkQuit();

	const bool& getQuit() const;

protected:
	bool quit;

	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	std::vector<sf::Texture> textures;

	virtual void initKeybinds() = 0;
};
