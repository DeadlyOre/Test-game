#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include"Player.h"
#include"utility.h"

void Bullet::update() {

}

void Bullet::render(sf::RenderWindow& window) {
	bullet.setPosition(sf::Vector2f{ x, y });
	window.draw(bullet);
}
