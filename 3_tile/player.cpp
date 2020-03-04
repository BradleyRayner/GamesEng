//player.cpp
#include "player.h"
using namespace sf;
using namespace std;

void Player::Update(double dt) {
	//Move in four directions based on keys
	//Move left
	if (Keyboard::isKeyPressed(Keyboard::A)) {

			move(Vector2f(-dt * 100, 0.0f));
	}
	//Move Right
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		move(Vector2f(dt * 100, 0.0f));
	}
	//Move Up
	if (Keyboard::isKeyPressed(Keyboard::W)) {

		move(Vector2f(0.0f, -dt * 100));
	}
	//Move Down
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		move(Vector2f(0.0f, dt * 100));
	}

		Entity::Update(dt);
}

Player::Player()
	: _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(Vector2f(25.f, 25.f));
}

void Player::Render(sf::RenderWindow &window) const {
	window.draw(*_shape);
}
