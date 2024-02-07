#include "Player.h"
#include <iostream>
void Player::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Blue);
	boundingRectangle.setOutlineThickness(1);

	size = sf::Vector2i(64, 64);
	
}

void Player::Load()
{
	if (texture.loadFromFile("Asset/Player/Texture/PlayerSheet.png"))
	{
		std::cout << "Player texture has been loaded!" << std::endl;
		sprite.setTexture(texture);

		//---Manipulasi Index---
		int xIndex = 0;
		int yIndex = 0;

		//---Implementasi---
		sprite.setTextureRect(sf::IntRect(xIndex, yIndex, size.x, size.y));

		//Manipulasi ukuran sprite
		sprite.setPosition(sf::Vector2f(960, 540));

		sprite.setScale(sf::Vector2f(3, 3));
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
	else
	{
		std::cout << "Player texture failed to loadded!" << std::endl;
	}
}

void Player::Update(Dummy& dummy)
{
	sf::Vector2f position = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.setPosition(position + sf::Vector2f(1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.setPosition(position - sf::Vector2f(1, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.setPosition(position - sf::Vector2f(0, 1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.setPosition(position + sf::Vector2f(0, 1));
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		bullets.push_back(sf::CircleShape(10));
		size_t i = bullets.size() - 1;
		bullets[i].setPosition(sprite.getPosition());
		bullets[i].setFillColor(sf::Color::Red);
	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		sf::Vector2f bulletDirection = dummy.sprite.getPosition() - bullets[i].getPosition();
		bulletDirection = Math::NormalizedVector(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
	}

	boundingRectangle.setPosition(sprite.getPosition());

	if (Math::DidRectColide(sprite.getGlobalBounds(), dummy.sprite.getGlobalBounds()))
	{
		std::cout << "Colision" << std::endl;
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);

	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}
