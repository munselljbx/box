#ifndef APP_BALL_HPP
#define APP_BALL_HPP

#include "Constant.hpp"
#include "IActor.hpp"

namespace app
{
class Ball : public IActor
{
public:
	Ball(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color, float radius);
	Ball(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color, float radius, float mass, float charge, float dragCoef = sphereDrag);
	virtual float getRadius() const;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::CircleShape m_circle;

	inline const static float sphereDrag = 0.47f;
};
}

#endif // APP_BALL_HPP