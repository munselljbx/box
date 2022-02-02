#include "World.hpp"

namespace app
{
World::World(sf::RenderWindow& window) :
	m_window(&window)
{}

void World::loop()
{
	nChargedBallsCircle(30, 300.f, 3);
	sf::Event event;
	while (m_window->isOpen())
	{
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window->close();
		}
		for (size_t i = 0U; i < m_actors.size(); i++)
		{
			m_actors[i]->update();
		}
		for (size_t i = 0U; i < m_actors.size(); i++)
		{
			m_actors[i]->influence(m_actors);
		}

		m_window->clear();
		for (size_t i = 0U; i < m_actors.size(); i++)
		{
			m_window->draw(*m_actors[i]);
		}
		m_window->display();
	}
}

void World::addActor(IActor* toAdd)
{
	m_actors.push_back(std::unique_ptr<IActor>(toAdd));
}

// Scenarios
void World::threeChargedBalls()
{
	using namespace std;
	m_actors.push_back(unique_ptr<IActor>(new Ball(sf::Vector2f(200.f, 200.f), sf::Vector2f(0.f, 0), sf::Color::Blue, 10.f)));
	m_actors.push_back(unique_ptr<IActor>(new Ball(sf::Vector2f(600.f, 300.f), sf::Vector2f(0.f, 2.f), sf::Color::Green, 10.f)));
	m_actors.push_back(unique_ptr<IActor>(new Ball(sf::Vector2f(900.f, 500.f), sf::Vector2f(0.f, 0), sf::Color::Red, 10.f)));
}

void World::nChargedBallsCircle(int n, float radius, float dotRadius)
{
	using namespace std;
	sf::Vector2f pos;
	sf::Color color = sf::Color::White;
	for (int i = 0; i < n; i++)
	{
		float p = (float)i / (float)n;
		float t = 2.f * (float)M_PI * p;
		pos.x = radius * cosf(t) + constant::windowSize.x / 2.f;
		pos.y = radius * sinf(t) + constant::windowSize.y / 2.f;
		color.g = static_cast<sf::Uint8>(p * 255.f);
		color.b = color.g;

		m_actors.push_back(unique_ptr<IActor>(new Ball(pos, sf::Vector2f(0.f, 0.f), color, dotRadius)));
	}
}

}