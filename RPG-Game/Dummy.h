#pragma once
#include <SFML/Graphics.hpp>

class Dummy
{
public:
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

private:
	sf::Texture texture;

public:
	sf::Sprite sprite;

public:
	void Initialize();
	void Load();

	void Update();
	void Draw(sf::RenderWindow& window) const;
};

