#include "Ball.hpp"

namespace app
{
Ball::Ball(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color, float radius) :
	IActor(position, velocity, sf::Vector2f(radius, radius), pow(radius, 3.f), pow(radius, 3.f)),
	m_circle(radius)
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