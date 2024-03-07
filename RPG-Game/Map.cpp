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
	if (texture.loadFromFile("Asset/Map/Sprite/Tileset.png"))
	{
		std::cout << "Map Texture Has Been Loaded !" << std::endl;

		totalTileX = texture.getSize().x / tileWidth;
		totalTileY = texture.getSize().y / tileHeight;

		std::cout << totalTileX << std::endl;
		std::cout << totalTileY << std::endl;

		for (size_t i = 0; i < 10; i++)
		{
			sprite[i].setTexture(texture);
			sprite[i].setTextureRect(sf::IntRect(i * tileWidth, 0 * tileHeight, tileWidth, tileHeight));
			sprite[i].setScale(sf::Vector2f(5, 5));
			sprite[i].setPosition(sf::Vector2f(100 + i * tileWidth * 5, 100));
		}
	}
	else
	{
		std::cout << "Texture Failed To Load !" << std::endl;
	}
}

void Map::Update(float deltaTime)
{

}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 10; i++)
	{
		window.draw(sprite[i]);
	}
}
