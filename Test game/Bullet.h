#pragma once

#include<SFML/graphics.hpp>

class Bullet {
public:

	const int speed = 15;
	float x;
	float y;
	
	sf::Vector2f direction;

	void update();
	void render(sf::RenderWindow& window);

	sf::CircleShape bullet{10};
};