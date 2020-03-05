#include "Button.h"

Button::Button(float _x, float _y, float _width, float _height, sf::Font* _font, std::string _text, sf::Color _idleColor, sf::Color _hoverColor, sf::Color _pressedColor) {
	this->buttonState = BTN_IDLE;
	
	this->shape.setPosition(sf::Vector2f(_x, _y));
	this->shape.setSize(sf::Vector2f(_width, _height));

	this->font = _font;
	this->text.setFont(*this->font);
	this->text.setString(_text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(36);
	this->text.setStyle(sf::Text::Bold);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	this->idleColor = _idleColor;
	this->hoverColor = _hoverColor;
	this->pressedColor = _pressedColor;

	this->shape.setFillColor(this->idleColor);
}

Button::~Button() {

}

void Button::update(const sf::Vector2f _mousePos) {
	
	this->prevState = this->buttonState;

	this->buttonState = BTN_IDLE;

	if (this->shape.getGlobalBounds().contains(_mousePos)) {
		this->buttonState = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
			this->buttonState = BTN_PRESSED;
	}

	switch (this->buttonState) {
	case BTN_IDLE:
		this->shape.setFillColor(this->idleColor);
		break;

	case BTN_HOVER:
		this->shape.setFillColor(this->hoverColor);
		break;

	case BTN_PRESSED:
		this->shape.setFillColor(this->pressedColor);
		break;

	default:
		this->shape.setFillColor(sf::Color::Red);
		break;
	}
}

void Button::render(sf::RenderTarget* _target) {
	_target->draw(this->shape);
	_target->draw(this->text);
}

const bool Button::isPressed() const {
	if (this->buttonState == BTN_PRESSED)
		return true;

	return false;
}

const bool Button::isReleased() const {
	if (this->buttonState == BTN_HOVER && this->prevState == BTN_PRESSED)
		return true;

	return false;
}