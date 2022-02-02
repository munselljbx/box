#ifndef APP_IACTOR_HPP
#define APP_IACTOR_HPP

#include "Constant.hpp"

namespace app
{
class IActor : public sf::Drawable, public sf::Transformable
{
public:
	IActor(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Vector2f& origin = sf::Vector2f(0.f, 0.f), float mass = 0.f, float charge = 0.f);
	virtual ~IActor()
	{}
	virtual void update();
	virtual void influence(std::vector<std::unique_ptr<IActor>>& actors);
	virtual void influence(IActor& actor);

	virtual float getRadius() const = 0;

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	float m_mass;
	float m_charge;
	sf::Vector2f m_vel;
	sf::Vector2f m_acc;
};
}

#endif // APP_IACTOR_HPP