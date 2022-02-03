#include "Ball.hpp"

namespace app
{
Ball::Ball(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color, float radius) :
	IActor(position, velocity, true, sf::Vector2f(radius, radius), pow(radius, 3.f), pow(radius, 3.f), sphereDrag),
	m_circle(radius, constant::circleNSides(radius))
{
	m_circle.setFillColor(color);
}
Ball::Ball(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color, float radius, float mass, float charge, float dragCoef) :
	IActor(position, velocity, true, sf::Vector2f(radius, radius), mass, charge, dragCoef),
	m_circle(radius, constant::circleNSides(radius))
{
	m_circle.setFillColor(color);
}

float Ball::getRadius() const
{
	return m_circle.getRadius();
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_circle, states);
}
}