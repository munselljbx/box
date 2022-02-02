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

private:
	sf::RenderWindow* m_window;
	std::vector<std::unique_ptr<IActor>> m_actors;
};
}

#endif // APP_WORLD_HPP