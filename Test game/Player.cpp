#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

void Player::render(sf::RenderWindow& window) {
	body.setPosition(sf::Vector2f{ x, y });
	window.draw(body);
}

void Player::handleInput(sf::Event event) {

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
}

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
}
