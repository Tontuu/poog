#include "engine.h"

// Constructor
Engine::Engine()
    : window(sf::VideoMode(640, 480), "Poog", sf::Style::Close | sf::Style::Titlebar),
      ball(15, sf::Color::White, sf::Vector2f(1.0f, 1.0f), sf::Vector2f(10, 10)),
      redPaddle(
	  sf::Vector2f(10, window.getSize().y / 4), sf::Color::Red,
	  sf::Vector2f(0, window.getSize().y / 2)),
      bluePaddle(
	  sf::Vector2f(10, window.getSize().y / 4), sf::Color::Blue,
	  sf::Vector2f(window.getSize().x - 10, window.getSize().y / 2))
{
    window.setFramerateLimit(60);
    backgroundColor = sf::Color(50, 50, 50);
    vel = 10;
}

// Functions
void Engine::run() {
    while (window.isOpen()) {
	checkEvents();
	update();
	render();
    }
}

// Check events like mouse, keyboard, close button and so on.
void Engine::checkEvents() {
    sf::Event event;

    while(window.pollEvent(event)) {
	if (event.type == sf::Event::Closed)
	    window.close();

	if (event.type == sf::Event::KeyPressed)
	    switch (event.key.code) {
		case (sf::Keyboard::Escape):
		    window.close();
		    break;
		case (sf::Keyboard::Up):
		    redPaddle.setVel(0, -vel);
		    break;
		case (sf::Keyboard::W):
		    redPaddle.setVel(0, -vel);
		    break;
		case (sf::Keyboard::Down):
		    redPaddle.setVel(0, vel);
		    break;
		case (sf::Keyboard::S):
		    redPaddle.setVel(0, vel);
		    break;
		default:
		    redPaddle.setVel(0, 0);
		    break;
	    }
	else if (event.type == sf::Event::KeyReleased)
	    redPaddle.setVel(0, 0);
    }
}

// Update game
void Engine::update() {
    ball.update();
    redPaddle.update();
    ball.hitWall(window);
    ball.hitPaddle(redPaddle);
    ball.hitPaddle(bluePaddle);
}

// Draw game
void Engine::render() {
    window.clear(backgroundColor);

    window.draw(ball);
    window.draw(redPaddle);
    window.draw(bluePaddle);

    window.display();
}
