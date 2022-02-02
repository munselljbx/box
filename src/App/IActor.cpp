#include "IActor.hpp"

namespace app
{
IActor::IActor(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Vector2f& origin, float mass, float charge)
{
	m_mass = mass;
	m_charge = charge;
	setOrigin(origin);
	setPosition(position);
	m_vel = velocity;
	m_acc = sf::Vector2f(0.f, 0.f);
}

void IActor::update()
{
	m_vel += m_acc;
	move(m_vel);
	m_acc = sf::Vector2f(0.f, 0.f);

	sf::Vector2f pos = getPosition();
	sf::Vector2f bound = constant::windowSize;
	if (pos.x > bound.x)
	{
		move(sf::Vector2f(2 * (bound.x - pos.x), 0.f));
		m_vel.x *= -1.f;
	}
	else if (pos.x < 0.f)
	{
		move(sf::Vector2f(2 * (-pos.x), 0.f));
		m_vel.x *= -1.f;
	}
	if (pos.y > bound.y)
	{
		move(sf::Vector2f(0.f, 2 * (bound.y - pos.y)));
		m_vel.y *= -1.f;
	}
	else if (pos.y < 0.f)
	{
		move(sf::Vector2f(0.f, 2 * (-pos.y)));
		m_vel.y *= -1.f;
	}
}

void IActor::influence(std::vector<std::unique_ptr<IActor>>& actors)
{
	for (size_t i = 0U; i < actors.size(); i++)
	{
		influence(*actors[i]);
	}
}

void IActor::influence(IActor& actor)
{
	sf::Vector2f r = actor.getPosition() - getPosition();
	if (actor.m_mass == 0.f || m_mass == 0.f || r.x == 0.f || r.y == 0.f)
		return;

	float overlap = (getRadius() + actor.getRadius()) - constant::v2fMag(r);
	if (overlap > 0.f)
	{
	}
	else
	{
		m_acc += (-constant::chargeStrength * actor.m_charge * m_charge / constant::v2fMag(r, 1.5f) / m_mass) * r;
	}
}
}