#include "Ball.hpp"

namespace app
{
Ball::Ball(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color, float radius) :
	IActor(sf::Vector2f(radius, radius), position, velocity),
	m_circle(radius)
{
	m_circle.setFillColor(color);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_circle, states);
}
}