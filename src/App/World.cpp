#include "World.hpp"

namespace app
{
World::World(sf::RenderWindow& window) :
	m_window(&window)
{}

void World::loop()
{
	using namespace std;
	//m_actors.push_back(unique_ptr<IActor>(new Mote(sf::Vector2f(400.f, 200.f), sf::Vector2f(5.f, 0.f), sf::Color::Red)));
	m_actors.push_back(unique_ptr<IActor>(new Ball(sf::Vector2f(200.f, 200.f), sf::Vector2f(0.f, 0), sf::Color::Blue, 10.f)));
	m_actors.push_back(unique_ptr<IActor>(new Ball(sf::Vector2f(600.f, 300.f), sf::Vector2f(0.f, 2.f), sf::Color::Green, 10.f)));
	m_actors.push_back(unique_ptr<IActor>(new Ball(sf::Vector2f(900.f, 500.f), sf::Vector2f(0.f, 0), sf::Color::Red, 10.f)));

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
}