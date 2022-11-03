#include "engine.h"
#include <iostream>
#include <cassert>

// struct LifeTexts {

//     LifeTexts(char redLifeCount, char blueLifeCount) {
// 	assert(font.loadFromFile("assets/fairfax.ttf"));
// 	redLife.setFont(font);
// 	blueLife.setFont(font);

// 	redLife.setString(redLifeCount);
// 	redLife.setPosition(0, 20);
// 	redLife.setFillColor(sf::Color::Red);

// 	blueLife.setString(blueLifeCount);
// 	blueLife.setPosition(window.getSize().x, 20);
// 	blueLife.setFillColor(sf::Color::Blue);
//     }
// };


// Constructor
Engine::Engine()
    : window(sf::VideoMode(640, 480), "Poog", sf::Style::Close | sf::Style::Titlebar),
      ball(10, sf::Color::White, sf::Vector2f(320.0f, 50.0f), sf::Vector2f(4, 4)),
      redPaddle(
	  sf::Vector2f(10, window.getSize().y / 4), sf::Color::Red,
	  sf::Vector2f(0, window.getSize().y / 2), 3),
      bluePaddle(
	  sf::Vector2f(10, window.getSize().y / 4), sf::Color::Blue,
	  sf::Vector2f(window.getSize().x - 10, window.getSize().y / 2), 3),
      lifeTexts(redPaddle.getLifeCount(), bluePaddle.getLifeCount())
{
    window.setFramerateLimit(60);
    backgroundColor = sf::Color(50, 50, 50);
    lifeTexts.redLife.setPosition(10, 5);
    lifeTexts.blueLife.setPosition(
	window.getSize().x - 10 - lifeTexts.blueLife.getLocalBounds().width, 5);
}

Engine::LifeTexts::LifeTexts(int redLifeCount, int blueLifeCount) {
    assert(font.loadFromFile("assets/fairfax.ttf"));

    redLife.setFont(font);
    blueLife.setFont(font);

    redLife.setFillColor(sf::Color::Red);
    blueLife.setFillColor(sf::Color::Blue);

    char redLifeCountChar = redLifeCount + '0';
    char blueLifeCountChar = blueLifeCount + '0';
    redLife.setString(redLifeCountChar);
    blueLife.setString(blueLifeCountChar);
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
void Engine::LifeTexts::update(int redLifeCount, int blueLifeCount) {
    redLife.setString(std::to_string(redLifeCount));
    blueLife.setString(std::to_string(blueLifeCount));
}

void Engine::checkHitWall() {
    int wallFlag = ball.hitWall(window);
    if (wallFlag == -1) {
	redPaddle.popLife();
	lifeTexts.update(redPaddle.getLifeCount(), bluePaddle.getLifeCount());
	window.clear(sf::Color::Red);
	window.display();
    } else if (wallFlag == 1) {
	bluePaddle.popLife();
	lifeTexts.update(redPaddle.getLifeCount(), bluePaddle.getLifeCount());
	window.clear(sf::Color::Blue);
	window.display();
    }
}

void Engine::update() {
    ball.update();
    redPaddle.update(window);
    bluePaddle.update(window);

    checkHitWall();

    ball.hitPaddle(redPaddle);
    ball.hitPaddle(bluePaddle);

    // TODO: Implement WIN state
    // TODO: Implement PAUSE state
}

// Draw game
void Engine::render() {
    window.clear(backgroundColor);

    window.draw(ball);
    window.draw(redPaddle);
    window.draw(bluePaddle);
    window.draw(lifeTexts.redLife);
    window.draw(lifeTexts.blueLife);

    window.display();
}
