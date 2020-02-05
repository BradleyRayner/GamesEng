//bullet.cpp
#include "bullet.h"
#include "ship.h"
#include "game.h"
using namespace sf;
using namespace std;

//Create definition for the constructor

unsigned char Bullet::bulletPointer;
Bullet Bullet::bullets[256];

Bullet::Bullet() {};

void Bullet::Init() {
	for (size_t i = 0; i < 256; i++)
	{
		bullets[i].setOrigin(16,16);
		bullets[i].setPosition(-999,-999);
		bullets[i].setTexture(spritesheet);
		bullets[i].setTextureRect(sf::IntRect(32,32,32,32));
	}
};

void Bullet::Update(const float &dt) {
	for (auto &b : bullets)
	{
		b._Update(dt);
	}
}
void Bullet::_Update(const float &dt) {
	if (getPosition().y < -32 || getPosition().y > gameHeight + 32) {
		//off screen - do nothing
		return;
	}
	else {
		move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
		const FloatRect boundingBox = getGlobalBounds();
		static float firetime = 0.0f;

		for (auto s : ships) {
			if (!_mode && s == player) {
				//player bulelts don't collide with player
				continue;
			}
			if (_mode && s != player) {
				//invader bullets don't collide with other invaders
				continue;
			}
			if (!s->is_exploded() &&
				s->getGlobalBounds().intersects(boundingBox)) {
				//Explode the ship
				s->Explode();
				//warp bullet off-screen
				setPosition(-100, -100);
				return;
			}
		}
	}
};

void Bullet::Render(sf::RenderWindow & window) {
	for (auto &b : bullets) {
		window.draw(b);
	}
};

void Bullet::Fire(const sf::Vector2f &pos, const bool mode) {
	bullets[bulletPointer].setPosition(pos);
	bullets[bulletPointer]._mode = mode;
	if (mode) {
		bullets[bulletPointer].setTextureRect(sf::IntRect(64, 32, 32, 32));
	}
	else {
		bullets[bulletPointer].setTextureRect(sf::IntRect(32, 32, 32, 32));
	}
	bulletPointer++;
};

void Ship::Explode() {
	setTextureRect(IntRect(128, 32, 32, 32));
	_exploded = true;
};