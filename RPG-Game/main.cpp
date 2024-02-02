#include "Player.h"
#include "Dummy.h"

int main()
{	
	//---------------------INITIALIZE-------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Arjuna", sf::Style::Default, settings);

	
	Player player;
	Dummy dummy;
	//---------------------INITIALIZE-------------------------
	player.Initialize();
	dummy.Initialize();
	//---------------------INITIALIZE-------------------------
	
	//------------------------LOAD----------------------------
	player.Load();
	dummy.Load();
	//------------------------LOAD----------------------------
	
	//-----------------------UPDATE---------------------------
	while (window.isOpen())
	{
			//----EVENT LOOP----
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
	//-----------------------UPDATE---------------------------
		player.Update(dummy);
		dummy.Update();
	//-----------------------UPDATE---------------------------
	
	//------------------------DRAW----------------------------
		window.clear(sf::Color::Black);
		dummy.Draw(window);
		player.Draw(window);
		window.display();
	//------------------------DRAW----------------------------
	}

	return 0;
}