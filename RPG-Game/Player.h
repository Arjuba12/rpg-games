#pragma once
#include<SFML/Graphics.hpp>
#include "Math.h"
#include "Dummy.h"

class Player
{
public:
	std::vector<sf::CircleShape> bullets;
	sf::Vector2f bulletDirection;
	float bulletSpeed = 1.0f;

private:
	sf::Texture texture;

public:
	sf::Sprite sprite;

public:
	void Initialize();
	void Load();

	void Update(Dummy& dummy);
	void Draw(sf::RenderWindow& window);
};

