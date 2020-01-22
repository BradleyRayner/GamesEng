#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


sf::Texture spritesheet;
sf::Sprite invader;
int gameWidth = 800;
int gameHeight = 800;

void Load() {
	if (!spritesheet.loadFromFile("res/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << std::endl;
	}
	invader.setTexture(spritesheet);
	invader.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void Render(RenderWindow &window) {
	window.draw(invader);
}


int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "Space Invaders");
	Load();
	while (window.isOpen()) {
		window.clear();
		//Update(window);
		Render(window);
		window.display();
	}
	return 0;
}