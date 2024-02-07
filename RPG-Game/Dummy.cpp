#include "Dummy.h"
#include <iostream>

void Dummy::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
}

void Dummy::Load()
{
	if (texture.loadFromFile("Asset/Dummy/Texture/DummySheet.png"))
	{
		std::cout << "Dummy texture has been loaded !" << std::endl;
		sprite.setTexture(texture);

		int xIndex = 0;
		int yIndex = 0;

		sprite.setTextureRect(sf::IntRect(xIndex, yIndex, size.x, size.y));
		sprite.setPosition(240 , 320);

		sprite.setScale(sf::Vector2f(3, 3));
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));

	}
	else
	{
		std::cout << "Dummy taxture failed to loaded!" << std::endl;
	}


}

void Dummy::Update()
{
	boundingRectangle.setPosition(sprite.getPosition());
}

void Dummy::Draw(sf::RenderWindow& window) const
{
	window.draw(boundingRectangle);
	window.draw(sprite);
}
