#include <Canvas.hpp>
#include <BoidShape.hpp>

using namespace sf;

Canvas::Canvas(int width, int height)
{
	Window.create(VideoMode(width, height), "Boids");
	QT = QuadTree(Vector2f(0, 0), Vector2f(width, height), 10);
}

void Canvas::SpawnBoidAt(int x, int y)
{
	QT.InsertAt(x,y);
}
void Canvas::Simulate()
{
	while(Window.isOpen())
	{
		Event e;
		while(Window.pollEvent(e))
			if(e.type == Event::Closed)
				Window.close();

		Window.clear();
		Draw();
		Window.display();
	}
}
void Canvas::Draw()
{
	BoidShape bs = BoidShape(12);
	auto boids = QT.GetAll(); 
	for(auto& boid : boids)
	{
		bs.setPosition(boid.GetPosition());
		Window.draw(bs);
	}
}