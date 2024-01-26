#include<SFML/Graphics.hpp>

int main()
{
	//---------------------INITIALIZE-------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Arjuna", sf::Style::Default,settings);


	sf::CircleShape shape(50.0f);
	sf::RectangleShape rectangle(sf::Vector2f(50,50));
	sf::CircleShape triangle(50.0f, 3);
	sf::CircleShape square(50.0f, 4);
	sf::CircleShape hexagon(50.0f, 8);
	//---------------------INITIALIZE-------------------------
	//Circle
	shape.setFillColor(sf::Color::Yellow);
	shape.setPosition(sf::Vector2f(100,100));
	shape.setOutlineThickness(5);
	shape.setOutlineColor(sf::Color::Green);
	//Rectangle
	rectangle.setSize(sf::Vector2f(100,100));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(sf::Vector2f(250, 100));
	rectangle.setOutlineThickness(5);
	rectangle.setOutlineColor(sf::Color::Green);
	//Triangle
	triangle.setScale(1.3f,1.3f);
	triangle.setFillColor(sf::Color::Cyan);
	triangle.setPosition(sf::Vector2f(400, 100));
	triangle.setOutlineThickness(5);
	triangle.setOutlineColor(sf::Color::Green);
	//Square
	square.setFillColor(sf::Color::Magenta);
	square.setPosition(sf::Vector2f(550,100));
	square.setOutlineThickness(5);
	square.setOutlineColor(sf::Color::Green);
	// Hexagon
	hexagon.setFillColor(sf::Color::Blue);
	hexagon.setPosition(sf::Vector2f(670, 100));
	hexagon.setOutlineThickness(5);
	hexagon.setOutlineColor(sf::Color::Green);
	//---------------------INITIALIZE-------------------------
	//GameLoop
	while (window.isOpen())
	{
	//-----------------------UPDATE---------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	//-----------------------UPDATE---------------------------

	//------------------------DRAW----------------------------
		window.clear(sf::Color::Black);
		window.draw(shape);
		window.draw(rectangle);
		window.draw(triangle);
		window.draw(square);
		window.draw(hexagon);
		window.display();
	//------------------------DRAW----------------------------
	}

	return 0;
}