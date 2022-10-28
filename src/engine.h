#pragma once
#ifndef engine_h
#define engine_h

#include <SFML/Graphics.hpp>
#include "ball.h"
#include "paddle.h"


class Engine {
private:
    // SFML Objects
    sf::RenderWindow window;
    sf::Color backgroundColor;

    // Objects
    Ball ball;
    Paddle redPaddle;
    Paddle bluePaddle;

    // Functions
    void update();
    void render();
    void checkEvents();

    // Variables
    float vel;

public:
    // Constructor
    Engine();

    // Public Functions
    void run();
};

#endif
