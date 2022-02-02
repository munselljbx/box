#include "Mote.hpp"

namespace app
{
Mote::Mote(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color) :
	IActor(position, velocity),
	m_vertex(sf::Vector2f(0.f, 0.f), color)
{}

void Mote::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(&m_vertex, 1U, sf::Points, states);
}
}