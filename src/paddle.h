#pragma once
#ifndef paddle_h
#define paddle_h

#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape {
private:
    sf::Vector2f vel;

public:
    // Constructor
    Paddle(sf::Vector2f size, sf::Color color, sf::Vector2f pos);

    // Public Functions
    void update();
    void setVel(float x, float y);
};

#endif
