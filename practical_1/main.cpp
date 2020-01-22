<<<<<<< HEAD
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
	Keyboard::A,
	Keyboard::Z,
	Keyboard::Up,
	Keyboard::Down
};

const Vector2f paddleSize(25.0f, 100.0f);
const float ballRadius = 10.0f;
const int gameWidth = 800;
const int gameHeight = 800;
const float paddleSpeed(400.0f);

Font font;
Text text;

int pointLeft;
int pointRight;
Vector2f ballVelocity;
bool server = false;

CircleShape ball;
RectangleShape paddles[2];

void Load() {
	//Set size and origin of paddles
	for (auto &p : paddles) {
		p.setSize(paddleSize - Vector2f(3, 3));
		p.setOrigin(paddleSize / 2.0f);
	}
	//Set size and origin of ball
	ball.setRadius(ballRadius - 3);
	ball.setOrigin(ballRadius / 2, ballRadius / 2);
	//Reset paddle position
	paddles[0].setPosition(10 + paddleSize.x / 2, gameHeight / 2);
	paddles[1].setPosition(gameWidth - 10 - paddleSize.x / 2, gameHeight / 2);
	paddles[0].setFillColor(sf::Color::Red);
	paddles[1].setFillColor(sf::Color::Blue);
	//Reset Ball Position
	ball.setPosition(gameWidth / 2, gameHeight / 2);
	//Set ball velocity
	ballVelocity = { (server ? 100.0f : -100.0f), 60.0f };
	
	// Load font-face from res dir
	font.loadFromFile("res/Roboto-Regular.ttf");
	// Set text element to use font
	text.setFont(font);
	// set the character size to 24 pixels
	text.setCharacterSize(24);
}

void Reset() {
	//Set size and origin of paddles
	for (auto &p : paddles) {
		p.setSize(paddleSize - Vector2f(3, 3));
		p.setOrigin(paddleSize / 2.0f);
	}
	//Set size and origin of ball
	ball.setRadius(ballRadius - 3);
	ball.setOrigin(ballRadius / 2, ballRadius / 2);
	//Reset paddle position
	paddles[0].setPosition(10 + paddleSize.x / 2, gameHeight / 2);
	paddles[1].setPosition(gameWidth - 10 - paddleSize.x / 2, gameHeight / 2);
	//Reset Ball Position
	ball.setPosition(gameWidth / 2, gameHeight / 2);
	//Set ball velocity
	ballVelocity = { (server ? 100.0f : -100.0f), 60.0f };

	// Update Score Text
	text.setString(pointLeft + " : " + pointRight);
	// Keep Score Text Centered
	text.setPosition((gameWidth * .5f) - (text.getLocalBounds().width * .5f), 0);
}
void Update(RenderWindow &window) {
	static Clock clock;
	float dt = clock.restart().asSeconds();
	ball.move(ballVelocity * dt);
	
	//Collision Detection

	// check ball collision
	const float bx = ball.getPosition().x;
	const float by = ball.getPosition().y;
	if (by > gameHeight) { //bottom wall
	  // bottom wall
		ballVelocity.x *= 1.1f;
		ballVelocity.y *= -1.1f;
		ball.move(0, -10);
	}
	else if (by < 0) { //top wall
   // top wall
		ballVelocity.x *= 1.1f;
		ballVelocity.y *= -1.1f;
		ball.move(0, 10);
	}
	else if (bx > gameWidth) {
		// right wall	
		pointRight++;
		Reset();
	}
	else if (bx < 0) {
		// left wall
		pointLeft++;
		Reset();
	}
	else if (
		//ball is inline or behind paddle
		bx <= paddleSize.x + ballRadius &&
		//AND ball is below top edge of paddle
		by >= paddles[0].getPosition().y - (paddleSize.y * 0.5) &&
		//AND ball is above bottom edge of paddle
		by <= paddles[0].getPosition().y + (paddleSize.y * 0.5)
		) {
		// bounce off left paddle
		ballVelocity.x = -ballVelocity.x * 1.1f;
	
	}
	else if (
		
		//ball is inline or behind paddle
		bx >= gameWidth - 2*ballRadius - paddleSize.x &&
		//AND ball is below top edge of paddle
		by >= paddles[1].getPosition().y - (paddleSize.y * 0.5) &&
		//AND ball is above bottom edge of paddle
		by <= paddles[1].getPosition().y + (paddleSize.y * 0.5)
		) {
		// bounce off right paddle
		ballVelocity.x = -ballVelocity.x* 1.1f;
		
	}

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

	// handle paddle movement
	float p1direction = 0.0f;
	float p2direction = 0.0f;

	if (Keyboard::isKeyPressed(controls[0])) {
		p1direction--;
	}
	if (Keyboard::isKeyPressed(controls[1])) {
		p1direction++;
	}

	if (Keyboard::isKeyPressed(controls[2])) {
		p2direction--;
	}
	if (Keyboard::isKeyPressed(controls[3])) {
		p2direction++;
	}
	paddles[0].move(0, p1direction * paddleSpeed * dt);
	paddles[1].move(0, p2direction * paddleSpeed * dt);


}


void Render(RenderWindow &window) {
	//Draw everything
	window.draw(paddles[0]);
	window.draw(paddles[1]);
	window.draw(ball);
}

int main(){
	RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
=======
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const Keyboard::Key controls[4] = {
	Keyboard::A,
	Keyboard::Z,
	Keyboard::Up,
	Keyboard::Down
};

const Vector2f paddleSize(25.0f, 100.0f);
const float ballRadius = 10.0f;
const int gameWidth = 800;
const int gameHeight = 800;
const float paddleSpeed(400.0f);

Font font;
Text text;

int pointLeft;
int pointRight;
Vector2f ballVelocity;
bool server = false;

CircleShape ball;
RectangleShape paddles[2];

void Load() {
	//Set size and origin of paddles
	for (auto &p : paddles) {
		p.setSize(paddleSize - Vector2f(3, 3));
		p.setOrigin(paddleSize / 2.0f);
	}
	//Set size and origin of ball
	ball.setRadius(ballRadius - 3);
	ball.setOrigin(ballRadius / 2, ballRadius / 2);
	//Reset paddle position
	paddles[0].setPosition(10 + paddleSize.x / 2, gameHeight / 2);
	paddles[1].setPosition(gameWidth - 10 - paddleSize.x / 2, gameHeight / 2);
	paddles[0].setFillColor(sf::Color::Red);
	paddles[1].setFillColor(sf::Color::Blue);
	//Reset Ball Position
	ball.setPosition(gameWidth / 2, gameHeight / 2);
	//Set ball velocity
	ballVelocity = { (server ? 100.0f : -100.0f), 60.0f };
	
	// Load font-face from res dir
	font.loadFromFile("res/Roboto-Regular.ttf");
	// Set text element to use font
	text.setFont(font);
	// set the character size to 24 pixels
	text.setCharacterSize(24);
}

void Reset() {
	//Set size and origin of paddles
	for (auto &p : paddles) {
		p.setSize(paddleSize - Vector2f(3, 3));
		p.setOrigin(paddleSize / 2.0f);
	}
	//Set size and origin of ball
	ball.setRadius(ballRadius - 3);
	ball.setOrigin(ballRadius / 2, ballRadius / 2);
	//Reset paddle position
	paddles[0].setPosition(10 + paddleSize.x / 2, gameHeight / 2);
	paddles[1].setPosition(gameWidth - 10 - paddleSize.x / 2, gameHeight / 2);
	//Reset Ball Position
	ball.setPosition(gameWidth / 2, gameHeight / 2);
	//Set ball velocity
	ballVelocity = { (server ? 100.0f : -100.0f), 60.0f };

	// Update Score Text
	text.setString(pointLeft + " : " + pointRight);
	// Keep Score Text Centered
	text.setPosition((gameWidth * .5f) - (text.getLocalBounds().width * .5f), 0);
}
void Update(RenderWindow &window) {
	static Clock clock;
	float dt = clock.restart().asSeconds();
	ball.move(ballVelocity * dt);
	
	//Collision Detection

	// check ball collision
	const float bx = ball.getPosition().x;
	const float by = ball.getPosition().y;
	if (by > gameHeight) { //bottom wall
	  // bottom wall
		ballVelocity.x *= 1.1f;
		ballVelocity.y *= -1.1f;
		ball.move(0, -10);
	}
	else if (by < 0) { //top wall
   // top wall
		ballVelocity.x *= 1.1f;
		ballVelocity.y *= -1.1f;
		ball.move(0, 10);
	}
	else if (bx > gameWidth) {
		// right wall	
		pointRight++;
		Reset();
	}
	else if (bx < 0) {
		// left wall
		pointLeft++;
		Reset();
	}
	else if (
		//ball is inline or behind paddle
		bx <= paddleSize.x + ballRadius &&
		//AND ball is below top edge of paddle
		by >= paddles[0].getPosition().y - (paddleSize.y * 0.5) &&
		//AND ball is above bottom edge of paddle
		by <= paddles[0].getPosition().y + (paddleSize.y * 0.5)
		) {
		// bounce off left paddle
		ballVelocity.x = -ballVelocity.x * 1.1f;
	
	}
	else if (
		
		//ball is inline or behind paddle
		bx >= gameWidth - 2*ballRadius - paddleSize.x &&
		//AND ball is below top edge of paddle
		by >= paddles[1].getPosition().y - (paddleSize.y * 0.5) &&
		//AND ball is above bottom edge of paddle
		by <= paddles[1].getPosition().y + (paddleSize.y * 0.5)
		) {
		// bounce off right paddle
		ballVelocity.x = -ballVelocity.x* 1.1f;
		
	}

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

	// handle paddle movement
	float p1direction = 0.0f;
	float p2direction = 0.0f;

	if (Keyboard::isKeyPressed(controls[0])) {
		p1direction--;
	}
	if (Keyboard::isKeyPressed(controls[1])) {
		p1direction++;
	}

	if (Keyboard::isKeyPressed(controls[2])) {
		p2direction--;
	}
	if (Keyboard::isKeyPressed(controls[3])) {
		p2direction++;
	}
	paddles[0].move(0, p1direction * paddleSpeed * dt);
	paddles[1].move(0, p2direction * paddleSpeed * dt);


}


void Render(RenderWindow &window) {
	//Draw everything
	window.draw(paddles[0]);
	window.draw(paddles[1]);
	window.draw(ball);
}

int main(){
	RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
>>>>>>> 69416714ee5f006121d2970eee5b61fa84d9f8e3
}