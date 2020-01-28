#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"
#include "game.h"
using namespace sf;
using namespace std;

std::vector<Ship *> ships;
sf::Texture spritesheet;


Sprite invader;
void Load() {
	Invader::speed = 40.f;
	if (!spritesheet.loadFromFile("res/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << std::endl;
	}
	/*float position_x = 32;
	float position_y = 32;
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		Invader* inv = new Invader(sf::IntRect(0, 0, 32, 32), { 100 + (position_x * count),100 });
		ships.push_back(inv);
		count++;
	}*/
	for (int r = 0; r < invaders_rows; ++r) {		
		auto rect = IntRect(32 * r, 0, 32, 32);
		for (int c = 0; c < invaders_columns; ++c) {
			float position_x = 100 + 32 * c;
			float position_y = 100 + 32 * r;
			Vector2f position = Vector2f(position_x,position_y);
			auto inv = new Invader(rect, position);
			ships.push_back(inv);
		}
	}
	
}

void Render(RenderWindow &window) {
	for (const auto s : ships) {
		window.draw(*s);
	}
}
void Update(RenderWindow &window) {
	static Clock clock;
	float dt = clock.restart().asSeconds();
	for (auto &s : ships) {
		s->Update(dt);
	};
}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "Space Invaders");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}