#include "utility.h"
#include <cmath>

sf::Vector2f sf::normalize(const sf::Vector2f& v) {
	float length = std::sqrt(v.x * v.x + v.y * v.y);
	return { v.x / length, v.y / length };
}