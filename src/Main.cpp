#include "App/Constant.hpp"
#include "App/World.hpp"
#include "Platform/Platform.hpp"

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	window.create(sf::VideoMode(app::constant::windowSize.x, app::constant::windowSize.y), "BOX", sf::Style::Close);
	platform.setIcon(window.getSystemHandle());
	window.setFramerateLimit(60);

	app::World world(window);
	world.loop();

	return 0;
}
