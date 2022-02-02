#ifndef APP_MOTE_HPP
#define APP_MOTE_HPP

#include "IActor.hpp"

namespace app
{
class Mote : public IActor
{
public:
	Mote(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color);
	virtual float getRadius() const;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::Vertex m_vertex;
};
}

#endif // APP_MOTE_HPP