#include "IActor.hpp"

namespace app
{
IActor::IActor(const sf::Vector2f& position, const sf::Vector2f& velocity, bool rigid, const sf::Vector2f& origin, float mass, float charge, float dragCoef)
{
	m_rigid = rigid;
	m_mass = mass;
	m_charge = charge;
	setOrigin(origin);
	setPosition(position);
	m_vel = velocity;
	m_acc = sf::Vector2f(0.f, 0.f);
	m_dragCoef = dragCoef;
}

void IActor::update()
{
	addForce(-m_vel * constant::dragStrength * m_dragCoef);
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

void IActor::influence(std::vector<std::unique_ptr<IActor>>& actors, size_t start)
{ // once per actor
	for (size_t i = start; i < actors.size(); i++)
	{
		influence(*actors[i]);
	}
}

void IActor::influence(IActor& actor)
{ // once per pair of actors
	sf::Vector2f r = actor.getPosition() - getPosition();
	if (actor.m_mass == 0.f || m_mass == 0.f || r.x == 0.f || r.y == 0.f)
		return;

	float overlap = (getRadius() + actor.getRadius()) - constant::v2fMag(r);
	if (overlap > 0.f)
	{
		if (m_rigid && actor.m_rigid)
			elasticCollide(actor, overlap);
	}
	else
	{ // no overlap
		// coloumb force
		sf::Vector2f force = -constant::chargeStrength * actor.m_charge * m_charge / constant::v2fMag(r, 1.5f) * r;
		addForce(force);
		actor.addForce(-force);
	}
}

void IActor::addForce(const sf::Vector2f& force)
{
	m_acc += force / m_mass;
}

void IActor::elasticCollide(IActor& actor, float overlap)
{
	sf::Vector2f r = actor.getPosition() - getPosition();
	sf::Vector2f rHat = r / constant::v2fMag(r);

	sf::Vector2f common = 1.f / (actor.m_mass + m_mass) * overlap * rHat;
	move(-actor.m_mass * common);
	actor.move(m_mass * common);

	float rSq = constant::v2fDot(r, r);
	float rDotV = constant::v2fDot(actor.m_vel - m_vel, r);
	common = 2.f / (m_mass + actor.m_mass) * rDotV / rSq * r;
	m_vel += actor.m_mass * common;
	actor.m_vel -= m_mass * common;
}
}