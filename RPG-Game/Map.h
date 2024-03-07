#pragma once
#include <SFML/Graphics.hpp>

class Map
{
private:
	sf::Texture texture;
	sf::Sprite sprite[10];
	
public:
	int tileWidth;
	int tileHeight;

	int totalTileX;
	int totalTileY;

public:
	Map();
	~Map();

	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

