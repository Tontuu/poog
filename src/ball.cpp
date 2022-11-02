#include "ball.h"
#include <iostream>

Ball::Ball(float radius, sf::Color color, sf::Vector2f pos, sf::Vector2f vel) : vel{vel} {
    setFillColor(color);
    setRadius(radius);
    setPosition(pos);
}

void Ball::update() {
    setPosition(getPosition().x + vel.x, getPosition().y + vel.y);
}

void Ball::hitWall(sf::RenderWindow& window) {
    if (getPosition().x + getRadius()*2 >= window.getSize().x || getPosition().x < 0) {
	// TODO(#2): Lose life function
	reverse(sf::Vector2f(-vel.x, vel.y));
    }

    if (getPosition().y + getRadius()*2 >= window.getSize().y || getPosition().y <= 0)
	reverse(sf::Vector2f(vel.x, -vel.y));
}

void Ball::hitPaddle(Paddle& paddle) {
    sf::FloatRect ballBounds = getGlobalBounds();
    sf::FloatRect paddleBounds = paddle.getGlobalBounds();

    if (ballBounds.intersects(paddleBounds)) {
	reverse(sf::Vector2f(-vel.x, vel.y));

        // Avoid glitching, it uses 10 as parameters to left or right paddle
	if (getPosition().x < 10) {
	    setPosition(paddle.getSize().x + 1, getPosition().y);
	} else {
	    setPosition(getPosition().x - paddle.getSize().x - 1, getPosition().y);
	}
    }
}

void Ball::reverse(sf::Vector2f newVel) {
    vel = newVel;
}
