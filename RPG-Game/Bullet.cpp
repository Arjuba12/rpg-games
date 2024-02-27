#include "Bullet.h"
#include "Math.h"

Bullet::Bullet():
	speed(0)
{

}

Bullet::~Bullet()
{

}

void Bullet::Initialize(const sf::Vector2f& position, const sf::Vector2f& target, float speed)
{
	this->speed = speed;
	circleShape = sf::CircleShape(10);
	circleShape.setFillColor(sf::Color::Red);
	circleShape.setPosition(position);
	direction = Math::NormalizedVector(target - position);
}

void Bullet::Update(float deltaTime)
{
	circleShape.setPosition(circleShape.getPosition() + direction * speed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(circleShape);
}
