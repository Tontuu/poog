#pragma once
#ifndef ball_h
#define ball_h

#include <SFML/Graphics.hpp>
#include "paddle.h"

class Ball : public sf::CircleShape {
private:
    // Functions
    void reverse(sf::Vector2f newVel);

    // Variables
    sf::Vector2f vel;

public:
    // Constructor
    Ball(float radius, sf::Color color, sf::Vector2f pos, sf::Vector2f vel);

    // Public Functions
    void update();
    void hitWall(sf::RenderWindow& window);
    void hitPaddle(Paddle& paddle);
};

#endif
