//ship.cpp
#include "ship.h"
#include "game.h"
#include "bullet.h"
using namespace sf;
using namespace std;

Ship::Ship() {};

Ship::Ship(IntRect ir) : Sprite() {
  _sprite = ir;
  setTexture(spritesheet);
  setTextureRect(_sprite);
};

void Ship::Update(const float &dt) {}

//Define the ship deconstructor. 
//Although we set this to pure virtual, we still have to define it.
Ship::~Ship() = default;



//ship.cpp
Invader::Invader() : Ship() {}

bool Invader::direction;
float Invader::speed;

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir) {
	setOrigin(16, 16);
	setPosition(pos);
}

void Invader::Update(const float &dt) {
	Ship::Update(dt);
	static float firetime = 0.0f;
	firetime -= dt;
	move(dt * (direction ? 1.0f : -1.0f) * speed, 0);

	if ((direction && getPosition().x > gameWidth - 16) ||
		(!direction && getPosition().x < 16)) {
		direction = !direction;
		for (int i = 1; i < ships.size(); ++i) {
			ships[i]->move(0, 24);
		}
	}
	if (firetime <= 0 && rand() % 100 == 0) {
		Bullet::Fire(getPosition(), true);
		firetime = 4.0f + (rand() % 60);
	}
}

//ship.cpp
Player::Player() : Ship(IntRect(160, 32, 32, 32)) {
	setPosition({ gameHeight * .5f, gameHeight - 32.f });
}


void Player::Update(const float &dt) {
	static vector<Bullet*> bullets;
	static float firetime = 0.0f;
	firetime -= dt;
	Ship::Update(dt);
	//Move left
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		
		if (getPosition().x > 0) {
			move(dt * -100, 0);
		}
		
	}
	//Move Right
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (getPosition().x < gameWidth - 32) {
			move(dt * 100, 0);
		}

	}
	//Fire bullet
	if (firetime <= 0 && Keyboard::isKeyPressed(Keyboard::W)) {
		Bullet::Fire(getPosition(), false);
		firetime = 0.7f;
	}
}


bool Ship::is_exploded() const
{
	return _exploded;
}
