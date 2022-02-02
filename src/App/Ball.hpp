#ifndef APP_BALL_HPP
#define APP_BALL_HPP

#include "IActor.hpp"

namespace app
{
class Ball : public IActor
{
public:
	Ball(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color, const float radius);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::CircleShape m_circle;
};
}

#endif // APP_BALL_HPP