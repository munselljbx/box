#ifndef APP_IACTOR_HPP
#define APP_IACTOR_HPP

#include "Constant.hpp"

namespace app
{
class IActor : public sf::Drawable, public sf::Transformable
{
public:
	IActor(const sf::Vector2f& position, const sf::Vector2f& velocity, bool rigid, const sf::Vector2f& origin = sf::Vector2f(0.f, 0.f), float mass = 0.f, float charge = 0.f, float dragCoef = 0.f);
	virtual ~IActor()
	{}
	virtual void update();
	virtual void influence(std::vector<std::unique_ptr<IActor>>& actors, size_t start);
	virtual void influence(IActor& actor);
	virtual void addForce(const sf::Vector2f& force);
	virtual void elasticCollide(IActor& actor, float overlap);

	virtual float getRadius() const = 0;

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	bool m_rigid;
	float m_mass;
	float m_charge;
	float m_dragCoef; // usually 0..1
	sf::Vector2f m_vel;
	sf::Vector2f m_acc;
};
}

#endif // APP_IACTOR_HPP