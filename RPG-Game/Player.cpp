#include "Player.h"
#include <iostream>


Player::Player() :
	playerSpeed(1.0f),
	maxFireRate(200),
	fireRateTimer(0),
	damage(5)
{

}

Player::~Player()
{

}

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
		sprite.setPosition(sf::Vector2f(320, 240));

		sprite.setScale(sf::Vector2f(2, 2));
		boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
	}
	else
	{
		std::cout << "Player texture failed to loadded!" << std::endl;
	}
}

void Player::Update(float deltaTime,Dummy& dummy, sf::Vector2f mousePosition)
{
	sf::Vector2f position = sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.setPosition(position - sf::Vector2f(1, 0) * playerSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.setPosition(position - sf::Vector2f(0, 1) * playerSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltaTime);
	}

	fireRateTimer += deltaTime;
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate)
	{
		bullets.push_back(Bullet());
		size_t i = bullets.size() - 1;
		bullets[i].Initialize(sprite.getPosition(),mousePosition, 0.5f); // yg terakhir bullet speed ya

		fireRateTimer = 0;
	}
	

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Update(deltaTime);

		if (dummy.health > 0)
		{
			if (Math::DidRectColide(bullets[i].GetGlobalBounds(), dummy.sprite.getGlobalBounds()))
			{
				bullets.erase(bullets.begin() + i);
				//std::cout << "Ughh..." << std::endl;
				dummy.health -= damage;
			}
		}
	}
	boundingRectangle.setPosition(sprite.getPosition());

	if (Math::DidRectColide(sprite.getGlobalBounds(), dummy.sprite.getGlobalBounds()))
	{
		/*std::cout << "Colision" << std::endl;*/
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);

	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Draw(window);
	}
}
