#include "Player.h"
#include <iostream>
void Player::Initialize()
{

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

		//---Rumus Posisi Render---
		int xValue = xIndex * 64;
		int yValue = yIndex * 64;

		//---Implementasi---
		sprite.setTextureRect(sf::IntRect(xValue, yValue, 64, 64));

		//Manipulasi ukuran sprite
		sprite.setScale(sf::Vector2f(3, 3));
		sprite.setPosition(sf::Vector2f(960, 540));
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
		int i = bullets.size() - 1;
		bullets[i].setPosition(sprite.getPosition());
		bullets[i].setFillColor(sf::Color::Red);
	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		sf::Vector2f bulletDirection = dummy.sprite.getPosition() - bullets[i].getPosition();
		bulletDirection = Math::NormalizedVector(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);

	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}
