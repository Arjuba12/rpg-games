#pragma once
#include <SFML/Graphics.hpp>

class Math
{
public:
	static sf::Vector2f NormalizedVector(sf::Vector2f vector);
	static bool DidRectColide(sf::FloatRect rect1, sf::FloatRect rect2);
};

