#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{
	std::vector<std::string> topTenAnime;
	topTenAnime.reserve(100);

	for (size_t i = 0; i < 100; i++)
	{
		topTenAnime.push_back("Boku no hero academia");
	}
	
	std::cout << "count: " << topTenAnime.size() << std::endl;
	std::cout << "capacity: " << topTenAnime.capacity() << std::endl;

	//---------------------INITIALIZE-------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Arjuna", sf::Style::Default, settings);

	//---------------------INITIALIZE-------------------------

	//------------------------LOAD----------------------------
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

	//-----------------------UPDATE---------------------------

	//------------------------DRAW----------------------------
		window.clear(sf::Color::Black);
		window.draw(dummySprite);
		window.draw(playerSprite);
		window.display();
		//------------------------DRAW----------------------------
	}

	return 0;
}