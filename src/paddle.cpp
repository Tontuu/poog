#include "paddle.h"
#include <iostream>

Paddle::Paddle(sf::Vector2f size, sf::Color color, sf::Vector2f pos) {
    setSize(size);
    setFillColor(color);
    setPosition(pos);
}

void Paddle::update(sf::RenderWindow& window) {
    // Check if some movement key has been pressed or not
    if (!(upFlag && downFlag)) // Neither key
	vel.y = 0;

    if (upFlag)   // Up key
	vel.y = -5;

    if (downFlag) // Down key
	vel.y = 5;

    // Check screen boundaries, use 10 as parameters to left and right paddle
    int x = (getPosition().x < 10) ? 0 : getPosition().x;

    if (getPosition().y <= 0)
	setPosition(x, 0);
    if (getPosition().y + getSize().y >= window.getSize().y)
	setPosition(x, window.getSize().y - getSize().y);

    move(vel);
}
