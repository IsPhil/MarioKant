#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* _window, std::map<std::string, int>* _supportedKeys) : State(_window, _supportedKeys) {
	this->initFonts();
	this->initKeybinds();
	this->initButtons();

	this->background.setSize(static_cast<sf::Vector2f>(_window->getSize()));
	this->background.setFillColor(sf::Color(0, 0, 0, 255));
}

MainMenuState::~MainMenuState() {
	for (auto i = this->buttons.begin(); i != this->buttons.end(); ++i) 
		delete i->second;
}

void MainMenuState::initFonts() {
	if (!this->font.loadFromFile("res/fonts/Silver.ttf"))
		throw("ERROR: Font konnte nicht geladen werden!!");
}

void MainMenuState::initKeybinds() {
	std::ifstream ifs("config/keybinds.ini");

	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
			this->keybinds[key] = this->supportedKeys->at(key2);
	} 

	ifs.close();
}

void MainMenuState::initButtons() {
	this->buttons["START"] = new Button(1280 / 2 - 75, 720 / 2 - 150, 200, 80,
		&this->font, "Start Game",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["SETTINGS"] = new Button(1280 / 2 - 75, 720 / 2 - 25, 200, 80,
		&this->font, "Settings",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["EXIT"] = new Button(1280 / 2 - 75, 720 / 2 + 150, 200, 80,
		&this->font, "Exit",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

void MainMenuState::updateInput(const float& _dTime) {
	this->checkQuit();
}

void MainMenuState::updateButtons() {
	for (auto& i : this->buttons)
		i.second->update(this->mousePosView);

	if (this->buttons["EXIT"]->isReleased())
		this->endState();
}

void MainMenuState::update(const float& _dTime) {
	this->updateMousePos();
	this->updateInput(_dTime);
	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* _target) {
	for (auto& i : this->buttons)
		i.second->render(_target);
}

void MainMenuState::render(sf::RenderTarget* _target) {
	if (!_target)
		_target = this->window;

	_target->draw(this->background);

	this->renderButtons(_target);
}

void MainMenuState::endState() {
	std::cout << "Ending tis bs." << std::endl;
	this->quit = true;
}
