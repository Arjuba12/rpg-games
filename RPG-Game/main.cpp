#include "Player.h"
#include "Dummy.h"
#include "FrameRate.h"
#include "Bullet.h"
#include <iostream> 

// Make a Class For The Frame Rate It So Messy !!

int main()
{
	//---------------------INITIALIZE-------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Arjuna", sf::Style::Default, settings);
	window.setFramerateLimit(360);

	Player player;
	Dummy dummy;
	FrameRate frameRate;

	//---------------------INITIALIZE-------------------------
	player.Initialize();
	dummy.Initialize();
	frameRate.Initialize();
	//---------------------INITIALIZE-------------------------

	//------------------------LOAD----------------------------
	player.Load();
	dummy.Load();
	frameRate.Load();
	
	//------------------------LOAD----------------------------
	sf::Clock clock;
	//-----------------------UPDATE---------------------------
	while (window.isOpen())
	{
		sf::Time deltaTimeTimer = clock.restart();
		double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;

		//----EVENT LOOP----
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

		//-----------------------UPDATE---------------------------
		frameRate.Update(deltaTime);
		dummy.Update(deltaTime);
		player.Update(deltaTime, dummy, mousePosition);
		//-----------------------UPDATE---------------------------

		//------------------------DRAW----------------------------
		window.clear(sf::Color::Black);

		dummy.Draw(window);
		player.Draw(window);
		frameRate.Draw(window);
		window.display();
		//------------------------DRAW----------------------------
	}

	return 0;
}