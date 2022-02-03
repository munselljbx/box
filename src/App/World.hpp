#ifndef APP_WORLD_HPP
#define APP_WORLD_HPP

#include "Ball.hpp"
#include "IActor.hpp"
#include "Mote.hpp"

namespace app
{
class World
{
public:
	World(sf::RenderWindow& window);
	void loop();
	void addActor(IActor* toAdd);

private:
	void threeChargedBalls();
	void nChargedBallsCircle(int n, float radius, float dotRadius);
	void noChargeElasticBalls();
	void chargedElasticBalls();
	void clusters(int n, float smallMass = 50.f);
	void cruelSatellite();
	void binaryOrbit();

	sf::RenderWindow* m_window;
	std::vector<std::unique_ptr<IActor>> m_actors;
};
}

#endif // APP_WORLD_HPP