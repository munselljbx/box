#ifndef APP_IACTOR_HPP
#define APP_IACTOR_HPP

#include "Constant.hpp"

namespace app
{
class IActor : public sf::Drawable, public sf::Transformable
{
public:
	IActor(const sf::Vector2f& position, const sf::Vector2f& velocity) :
		m_vel(velocity)
	{
		setPosition(position);
	}
	IActor(const sf::Vector2f& origin, const sf::Vector2f& position, const sf::Vector2f& velocity) :
		m_vel(velocity)
	{
		setOrigin(origin);
		setPosition(position);
	}
	virtual ~IActor() = default;
	virtual void update()
	{
		move(m_vel);

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

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	sf::Vector2f m_vel;
};
}

#endif // APP_IACTOR_HPP