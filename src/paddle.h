#pragma once
#ifndef paddle_h
#define paddle_h

#include <SFML/Graphics.hpp>
#include <vector>

class Paddle : public sf::RectangleShape {
private:
    sf::Vector2f vel;

public:

    // Constructor
    Paddle(sf::Vector2f size, sf::Color color, sf::Vector2f pos);

    // Public Functions
    void update(sf::RenderWindow& window);

    // Resources
    bool upFlag = false;
    bool downFlag = false;
};

#endif
