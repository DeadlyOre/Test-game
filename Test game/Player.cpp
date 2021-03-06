#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include"utility.h"

//Player rendering
void Player::render(sf::RenderWindow& window) {
	body.setPosition(sf::Vector2f{ x, y });
	window.draw(body);

    for (int i = 0; i < bullets.size(); ++i) {
        bullets[i].render(window);
    }
}

//Player input
void Player::handleInput(sf::Event event) {

    //Keyboard input
    if (event.type == sf::Event::KeyPressed) {

        if (event.key.code == sf::Keyboard::W) {
            upKey = true;
        }
        if (event.key.code == sf::Keyboard::A) {
            leftKey = true;
        }
        if (event.key.code == sf::Keyboard::S) {
            downKey = true;
        }
        if (event.key.code == sf::Keyboard::D) {
            rightKey = true;
        }
    }
    else if (event.type == sf::Event::KeyReleased) {

        if (event.key.code == sf::Keyboard::W) {
            upKey = false;
        }
        if (event.key.code == sf::Keyboard::A) {
            leftKey = false;
        }
        if (event.key.code == sf::Keyboard::S) {
            downKey = false;
        }
        if (event.key.code == sf::Keyboard::D) {
            rightKey = false;
        }
    }
    //Mouse input
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f bodySize = body.getSize();
        sf::Vector2f center{ x + bodySize.x / 2, y + bodySize.y / 2 };
        sf::Vector2f diff{ event.mouseButton.x - center.x, event.mouseButton.y - center.y };
        Bullet b;
        b.direction = sf::normalize(diff);
        b.x = center.x;
        b.y = center.y;
        bullets.push_back(b);
    }
}

//Player movement
void Player::update() {
    if (upKey) {
        velY -= acc;
    }
    if (downKey) {
        velY += acc;
    }
    if (leftKey) {
        velX -= acc;
    }
    if (rightKey) {
        velX += acc;
    }

    velY *= 1.0 - fric;
    velX *= 1.0 - fric;

    y += velY;
    x += velX;

    //update bullets
    for (int i = 0; i < bullets.size(); ++i)
    {
        bullets[i].update();
    }
}
