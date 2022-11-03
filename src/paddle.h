#pragma once
#ifndef paddle_h
#define paddle_h

#include <SFML/Graphics.hpp>
#include <vector>

class Paddle : public sf::RectangleShape {
private:
    sf::Vector2f vel;
    int lifeCount;

public:

    // Constructor
    Paddle(sf::Vector2f size, sf::Color color, sf::Vector2f pos, int life);

    // Public Functions
    void update(sf::RenderWindow& window);

    // Resources
    bool upFlag = false;
    bool downFlag = false;
    void popLife();
    int getLifeCount();
};

#endif
