#pragma once

#include<SFML/graphics.hpp>

class Bullet {
public:

	const int speed = 5;
	int x;
	int y;
	
	sf::Vector2f direction;

	void update();
	void render(sf::RenderWindow& window);

	sf::RectangleShape bullet{ sf::Vector2f{8, 8} };
};

