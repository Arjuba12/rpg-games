#pragma once
#include <SFML/Graphics.hpp>

class Dummy
{
public:
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;

	int health;
private:
	sf::Texture texture;

	sf::Font font;
	sf::Text healthText;

public:
	sf::Sprite sprite;

public:
	Dummy();
	~Dummy();
	void Initialize();
	void Load();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window) const;
};

