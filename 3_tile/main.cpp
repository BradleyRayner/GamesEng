#include <SFML/Graphics.hpp>
#include <iostream>
//#include "game.h"
#include "player.h"
#include "LevelSystem.h"

using namespace sf;
using namespace std;

int gameWidth = 800;
int gameHeight = 800;
Player *player;
void Load() {
	player = new Player();
	ls::loadLevelFile("res/maze_2.txt");

	// Print the level to the console
	for (size_t y = 0; y < ls::getHeight(); ++y) {
		for (size_t x = 0; x < ls::getWidth(); ++x) {
			cout << ls::getTile({ x, y });
		}
		cout << endl;
	}
}

void Render(RenderWindow &window) {
	player->Render(window);
}

void Update(RenderWindow &window) {
	static Clock clock;
	float dt = clock.restart().asSeconds();
	player->Update(dt);

	ls::Render(window);

	//Check if window closed
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}

	// Quit Via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}


}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "Tile Engine");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}