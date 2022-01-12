#pragma once

#include<SFML/graphics.hpp>


class Player {
public:

    float x = 0;
    float y = 0;

    float velX = 0;
    float velY = 0;

    const float acc = 0.7;
    const float fric = 0.1;

    bool upKey = false;
    bool downKey = false;
    bool leftKey = false;
    bool rightKey = false;

    void render(sf::RenderWindow& window);
    void handleInput(sf::Event event);
    void update();

    sf::RectangleShape body{ sf::Vector2f{64, 64 } };
};

