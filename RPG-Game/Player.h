#pragma once
#include<SFML/Graphics.hpp>
#include "Math.h"
#include "Dummy.h"
#include "Bullet.h"


class Player
{
public:
	std::vector<Bullet> bullets;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;
	sf::Vector2f bulletDirection;

	float playerSpeed;
	float maxFireRate;
	float fireRateTimer;
	int damage;

private:
	sf::Texture texture;

public:
	sf::Sprite sprite;

public:
	Player();
	~Player();

	void Initialize();
	void Load();

	void Update(float deltaTime,Dummy& dummy, sf::Vector2f mousePosition);
	void Draw(sf::RenderWindow& window);
};

