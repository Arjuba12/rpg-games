#include "Dummy.h"
#include <iostream>

void Dummy::Initialize()
{

}

void Dummy::Load()
{
	if (texture.loadFromFile("Asset/Dummy/Texture/DummySheet.png"))
	{
		std::cout << "Dummy texture has been loaded !" << std::endl;
		sprite.setTexture(texture);

		int xIndex = 0;
		int yIndex = 0;

		int xValue = xIndex * 64;
		int yValue = yIndex * 64;

		sprite.setTextureRect(sf::IntRect(xValue, yValue, 64, 64));
		sprite.setScale(3, 3);

	}
	else
	{
		std::cout << "Dummy taxture failed to loaded!" << std::endl;
	}
}

void Dummy::Update()
{

}

void Dummy::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
