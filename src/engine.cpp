#include "engine.h"

// Constructor
Engine::Engine()
    : window(sf::VideoMode(640, 480), "Poog", sf::Style::Close | sf::Style::Titlebar),
      ball(10, sf::Color::White, sf::Vector2f(320.0f, 50.0f), sf::Vector2f(4, 4)),
      redPaddle(
	  sf::Vector2f(10, window.getSize().y / 4), sf::Color::Red,
	  sf::Vector2f(0, window.getSize().y / 2)),
      bluePaddle(
	  sf::Vector2f(10, window.getSize().y / 4), sf::Color::Blue,
	  sf::Vector2f(window.getSize().x - 10, window.getSize().y / 2))
{
    window.setFramerateLimit(60);
    backgroundColor = sf::Color(50, 50, 50);
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
	    switch(event.key.code) {
		case sf::Keyboard::Escape : window.close(); break;
		case sf::Keyboard::Up     : redPaddle.upFlag = true; break;
		case sf::Keyboard::W      : redPaddle.upFlag = true; break;
		case sf::Keyboard::K      : redPaddle.upFlag = true; break;
		case sf::Keyboard::Down   : redPaddle.downFlag = true; break;
		case sf::Keyboard::S      : redPaddle.downFlag = true; break;
		case sf::Keyboard::J      : redPaddle.downFlag = true; break;
		default: break;
	    }

	if (event.type == sf::Event::KeyReleased)
	    switch(event.key.code) {
		case sf::Keyboard::Up     : redPaddle.upFlag = false; break;
		case sf::Keyboard::W      : redPaddle.upFlag = false; break;
		case sf::Keyboard::K      : redPaddle.upFlag = false; break;
		case sf::Keyboard::Down   : redPaddle.downFlag = false; break;
		case sf::Keyboard::S      : redPaddle.downFlag = false; break;
		case sf::Keyboard::J      : redPaddle.downFlag = false; break;
		default: break;
	    }
    }
}

// Update game
void Engine::update() {
    ball.update();
    redPaddle.update(window);
    bluePaddle.update(window);

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
