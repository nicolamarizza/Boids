#include <SFML/Graphics.hpp>
#include <LALG/Vector2.hpp>
#include <BoidShape.hpp>
#include <Boid.hpp>
#include <Canvas.hpp>
#include <cstdlib>
#include <time.h>
#include <UIMath.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

constexpr int WINDOW_WIDTH = 1920;
constexpr int WINDOW_HEIGHT = 1080;

int main()
{
	srand (time(NULL));

	Canvas canvas(WINDOW_WIDTH, WINDOW_HEIGHT);
	for(int i = 0; i < WINDOW_WIDTH; i+= 50)
		for(int j = 0; j < WINDOW_HEIGHT; j+= 60)
			canvas.SpawnBoidAt(i,j);

	canvas.Simulate();


	return 0;
}

/*
int main()
{
	RenderWindow Window(VideoMode(800,800),"");
	BoidShape s0 = BoidShape(12);

	s0.setPosition(400,400);
	s0.setFillColor(Color::White);

	while(Window.isOpen())
	{
		Event e;
		while(Window.pollEvent(e))
			if(e.type == Event::Closed)
				Window.close();

		Window.clear();
		auto v = (Vector2f)Mouse::getPosition(Window) - Vector2f(400,400);
		auto a = UIMath::GetAngle(v);
		auto d = UIMath::ToDegrees(a);
		std::cout << '[' << v.x << ',' << -v.y << ']' << " -> " << d << std::endl;
		s0.setRotation(d + 90);
		Window.draw(s0);
		Window.display();
	}
}*/