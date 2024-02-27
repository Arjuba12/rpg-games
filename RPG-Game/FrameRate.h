#pragma once
#include<SFML/Graphics.hpp>


class FrameRate
{
private:
	sf::Font font;
	sf::Text frameRateText;
	double timer;

public:

	FrameRate();
	~FrameRate();
	void Initialize();
	void Load();

	void Update(double deltaTime);
	void Draw(sf::RenderWindow& window);
};

