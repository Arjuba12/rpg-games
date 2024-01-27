#include<SFML/Graphics.hpp>
#include <iostream>

int main()
{
	//---------------------INITIALIZE-------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Arjuna", sf::Style::Default,settings);

	//---------------------INITIALIZE-------------------------

	//------------------------LOAD----------------------------
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Asset/Player/Texture/PlayerSheet.png"))
	{
		std::cout << "Texture has been loaded!" << std::endl;
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
	}
	else
	{
		std::cout << "Texture is not loadded!" << std::endl;
	}

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

	//-----------------------UPDATE---------------------------

	//------------------------DRAW----------------------------
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.display();
	//------------------------DRAW----------------------------
	}

	return 0;
}