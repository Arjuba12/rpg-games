#pragma once
#include <SFML/Graphics.hpp>
#include"Tile.h"

class Map
{
private:
	sf::Texture tileSheetTexture;

	Tile* tiles;
	
	int tileWidth;
	int tileHeight;

	int totalTiles;

	int totalTileX;
	int totalTileY;

	int mapNumbers[6] ={
		2, 3, 3,
		5, 5, 4
	};

	sf::Sprite mapSprite[6];

public:
	Map();
	~Map();

	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
};

