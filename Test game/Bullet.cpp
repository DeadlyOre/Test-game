#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include"Player.h"
#include"utility.h"

void Bullet::update() {
	x += direction.x * speed;
	y += direction.x * speed;
}

void Bullet::render(sf::RenderWindow& window) {
	bullet.setPosition(sf::Vector2f{ (float)x, (float)y });
	window.draw(bullet);
	bullet.setFillColor(sf::Color{ 255,0,0 });
}
