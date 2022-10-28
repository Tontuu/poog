#include "paddle.h"

Paddle::Paddle(sf::Vector2f size, sf::Color color, sf::Vector2f pos) {
    setSize(size);
    setFillColor(color);
    setPosition(pos);
}

void Paddle::update() {
    move(vel);
}

void Paddle::setVel(float x, float y) {
    vel.x = x;
    vel.y = y;
}
