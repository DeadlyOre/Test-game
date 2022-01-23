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
	y += direction.y * speed;
}

void Bullet::render(sf::RenderWindow& window) {
	bullet.setPosition(sf::Vector2f{ (float)x, (float)y });
	bullet.setFillColor(sf::Color{ 255,255,0 });
	window.draw(bullet);
}
