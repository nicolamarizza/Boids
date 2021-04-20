#include <SFML/Graphics.hpp>
#include <LALG/Vector2.hpp>
#include <BoidShape.hpp>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800,800), "Boids");

	while(window.isOpen())
	{
		Event e;
		while(window.pollEvent(e))
			if(e.type == Event::Closed)
				window.close();

		window.clear();
		window.display();
	}

	return 0;
}