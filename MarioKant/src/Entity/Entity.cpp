#include "Entity.h"

Entity::Entity() {
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::Green);
	this->moveSpeed = 500.f;
}

Entity::~Entity() {
	
}

void Entity::update(const float& _dTime) {

}

void Entity::render(sf::RenderTarget* _target) {
	_target->draw(this->shape);
}

void Entity::move(const float _dir_x, const float _dir_y, const float& _dTime) {
	this->shape.move(_dir_x * this->moveSpeed * _dTime, _dir_y * this->moveSpeed * _dTime);
}