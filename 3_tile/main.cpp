#include <SFML/Graphics.hpp>
#include "entity.h"
#include "player.h"
#include "game.h"
#include "Levelsystem.h"

using namespace sf;
using namespace std;

Player* player;

void Load()
{
	ls::loadLevelFile("./res/maze_2.txt");
	for (size_t y = 0; y < ls::getHeight(); ++y) {
		for (size_t x = 0; x < ls::getWidth(); ++x) {
			cout << ls::getTile({ x, y });
		}
		cout << endl;
	}
	player = new Player;
}

void Update(RenderWindow& window)
{
	static Clock clock;
	float dt = clock.restart().asSeconds();
	player->Update(dt);
}

void Render(RenderWindow& window)
{
	ls::Render(window);
	player->Render(window);
}

int main() {
	sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Tile Engine");
	Load();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}
		window.clear();
		Update(window);
		Render(window);
		window.display();

	}
	return 0;
}