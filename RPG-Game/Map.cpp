#include "Map.h"
#include <iostream>

Map::Map():
	tileWidth(16),
	tileHeight(16)
{

}

Map::~Map()
{

}

void Map::Initialize()
{

}

void Map::Load()
{
	if (tileSheetTexture.loadFromFile("Asset/Map/Sprite/Tileset.png"))
	{
		std::cout << "Map Texture Has Been Loaded !" << std::endl;

		totalTileX = tileSheetTexture.getSize().x / tileWidth;
		totalTileY = tileSheetTexture.getSize().y / tileHeight;
		
		totalTiles = totalTileX * totalTileY;

		tiles = new Tile[totalTiles];

		for (size_t y = 0; y < totalTileY; y++)
		{
			for (size_t x = 0; x < totalTileX; x++)
			{
				int i = x + y * totalTileX;

				tiles[i].id = i;

				tiles[i].position = sf::Vector2i(x * tileWidth, x * tileHeight);
			}
		}

	}
	else
	{
		std::cout << "Texture Failed To Load !" << std::endl;
	}

	for (size_t y = 0; y < 2; y++)
	{
		for (size_t x = 0; x < 3; x++)
		{
			int i = x + y * 3;
			int index = mapNumbers[i];

			mapSprite[i].setTexture(tileSheetTexture);

			mapSprite[i].setTextureRect(sf::IntRect(
				tiles[index].position.x,
				tiles[index].position.y,
				tileWidth,
				tileHeight));

			mapSprite[i].setScale(sf::Vector2f(3, 3));
			mapSprite[i].setPosition(sf::Vector2f(x * 16 * 3, y * 16 * 3));
		}
	}
}

void Map::Update(float deltaTime)
{

}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 6; i++)
	{
		window.draw(mapSprite[i]);
	}
}
