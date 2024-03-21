#include "Dummy.h"
#include <iostream>

Dummy::Dummy() : 
	health(100)
{

}

Dummy::~Dummy()
{

}

void Dummy::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
}

void Dummy::Load()
{
	if (font.loadFromFile("Asset/Fonts/arial.ttf"))
	{
		std::cout << "Health Font Loaded" << std::endl;
		healthText.setFont(font);
		
	}

	if (texture.loadFromFile("Asset/Dummy/Texture/DummySheet.png"))
	{
		std::cout << "Dummy texture has been loaded !" << std::endl;
		sprite.setTexture(texture);

		int xIndex = 0;
		int yIndex = 0;

		sprite.setTextureRect(sf::IntRect(xIndex, yIndex, size.x, size.y));
		sprite.setPosition(64 , 64);

		sprite.setScale(sf::Vector2f(2, 2));
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));

	}
	else
	{
		std::cout << "Dummy taxture failed to loaded!" << std::endl;
	}

	

}

void Dummy::Update(float deltaTime)
{
	boundingRectangle.setPosition(sprite.getPosition());
	healthText.setString(std::to_string(int(health)));
	healthText.setPosition(sprite.getPosition());

	if (health <= 0)
	{
		// std::cout << "Am Dead ..." << std::endl;
	}
}

void Dummy::Draw(sf::RenderWindow& window) const
{
	if (health > 0)
	{
		window.draw(boundingRectangle);
		window.draw(healthText);
		window.draw(sprite);
	}
	
}
