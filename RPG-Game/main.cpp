#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

static sf::Vector2f NormalizedVector(sf::Vector2f vector)
{
	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	sf::Vector2f normalizedVector;

	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

int main()
{	
	//---------------------INITIALIZE-------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Arjuna", sf::Style::Default, settings);

	//---------------------INITIALIZE-------------------------
	
	//------------------------LOAD----------------------------
	//--- Peluru ---
	std::vector<sf::CircleShape> bullets;
	sf::Vector2f bulletDirection;
	float bulletSpeed = 1.0f;
	//--- Peluru ---

	//--- Dummy ---
	sf::Texture dummyTexture;
	sf::Sprite dummySprite;

	if (dummyTexture.loadFromFile("Asset/Dummy/Texture/DummySheet.png"))
	{
		std::cout << "Dummy texture has been loaded !" << std::endl;
		dummySprite.setTexture(dummyTexture);

		int xIndex = 0;
		int yIndex = 0;

		int xValue = xIndex * 64;
		int yValue = yIndex * 64;

		dummySprite.setTextureRect(sf::IntRect(xValue, yValue, 64, 64));
		dummySprite.setScale(3, 3);
		
	}
	else
	{
		std::cout << "Dummy taxture failed to loaded!" << std::endl;
	}
	//--- Dummy ---

	//--- Player ---
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Asset/Player/Texture/PlayerSheet.png"))
	{
		std::cout << "Player texture has been loaded!" << std::endl;
		playerSprite.setTexture(playerTexture);

		//---Manipulasi Index---
		int xIndex = 0;
		int yIndex = 0;

		//---Rumus Posisi Render---
		int xValue = xIndex * 64;
		int yValue = yIndex * 64;

		//---Implementasi---
		playerSprite.setTextureRect(sf::IntRect(xValue, yValue, 64, 64));

		//Manipulasi ukuran sprite
		playerSprite.setScale(sf::Vector2f(3, 3));
		playerSprite.setPosition(sf::Vector2f(960, 540));
	}
	else
	{
		std::cout << "Player texture failed to loadded!" << std::endl;
	}
	//--- Player ---

	//------------------------LOAD----------------------------
	//GameLoop
	while (window.isOpen())
	{
		//-----------------------UPDATE---------------------------
			//----EVENT LOOP----
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//-------------------PlayerMovement-------------------
		sf::Vector2f position = playerSprite.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			playerSprite.setPosition(position + sf::Vector2f(1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			playerSprite.setPosition(position - sf::Vector2f(1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			playerSprite.setPosition(position - sf::Vector2f(0, 1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			playerSprite.setPosition(position + sf::Vector2f(0, 1));
		}
		//-------------------PlayerMovement-------------------
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			bullets.push_back(sf::CircleShape(10));
			int i = bullets.size() - 1;
			bullets[i].setPosition(playerSprite.getPosition());
			bullets[i].setFillColor(sf::Color::Red);
			
		}

		for (size_t i = 0; i < bullets.size(); i++)
		{		
			bulletDirection = dummySprite.getPosition() - bullets[i].getPosition();
			bulletDirection = NormalizedVector(bulletDirection);
			bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
		}
	//-----------------------UPDATE---------------------------

	//------------------------DRAW----------------------------
		window.clear(sf::Color::Black);
		window.draw(dummySprite);
		window.draw(playerSprite);
		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}
		//window.draw(bullet);
		window.display();
		//------------------------DRAW----------------------------
	}

	return 0;
}