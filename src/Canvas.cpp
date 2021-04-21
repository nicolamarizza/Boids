#include <Canvas.hpp>
#include <BoidShape.hpp>

using namespace sf;

Canvas::Canvas(int width, int height)
{
	Window.create(VideoMode(width, height), "Boids");
	QT = QuadTree(Vector2f(0, 0), Vector2f(width, height), 10);
	LastRefresh = Clock();
}

void Canvas::SpawnBoidAt(int x, int y)
{
	auto pos = Vector2f(x,y);
	SpawnedBoids.push_back(Boid(81, pos));
	QT.InsertAt(pos, &SpawnedBoids.back());
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
		UpdateBoids();
		RefreshQtree();
		AssignFlocks();
		Draw();
		Window.display();
	}
}
void Canvas::Draw()
{
	BoidShape bs = BoidShape(12);
	for(auto& boid : SpawnedBoids)
	{
		bs.setPosition(boid.GetPosition());
		Window.draw(bs);
	}
}

void Canvas::UpdateBoids()
{
	float elapsedSeconds = LastRefresh.getElapsedTime().asSeconds();
	for(auto& boid : SpawnedBoids)
		boid.Update(elapsedSeconds);

	LastRefresh.restart();
}
void Canvas::RefreshQtree()
{
	QT.Clear();
	for(auto& boid : SpawnedBoids)
		QT.InsertAt(boid.GetPosition(), &boid);
}
void Canvas::AssignFlocks()
{
	for(auto& boid : SpawnedBoids)
		boid.AssignToFlock(QT.GetClosestTo(boid.GetPosition(), boid.GetPerception()));
}