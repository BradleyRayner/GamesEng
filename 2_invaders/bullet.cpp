//bullet.cpp
#include "bullet.h"
//#include "game.h"
using namespace sf;
using namespace std;

//Create definition for the constructor

//Bullet::Bullet() : Sprite() {
//	setTexture(spritesheet);
//	if (_mode) {
//		setTextureRect(IntRect(64, 32, 32, 32));
//	}
//	else {
//		setTextureRect(IntRect(32, 32, 32, 32));
//	}
//
//};

void Bullet::Update(const float &dt) {
    move(0, dt * 200.0f * (_mode ? 1.0f : -1.0f));
}