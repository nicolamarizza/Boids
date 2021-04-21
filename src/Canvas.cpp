#include <Canvas.hpp>
#include <BoidShape.hpp>
#include <UIMath.hpp>
#include <cstdlib>
#include <time.h>
using namespace sf;

Canvas::Canvas(int width, int height)
{
	Window.create(VideoMode(width, height), "Boids");
	QT = QuadTree(Vector2f(0, 0), Vector2f(width, height), 3);
	LastRefresh = Clock();
	LastRefresh.restart();
}

void Canvas::SpawnBoidAt(int x, int y)
{
	auto pos = Vector2f(x,y);
	Boid boid = Boid(60, pos);
	boid.SetVelocity(Vector2f( -100 + rand() % 200, -100 + rand() % 200));
	SpawnedBoids.push_back(boid);
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

		Window.clear(Color(20,20,100,255));
		UpdateBoidsPositions();
		RefreshQtree();
		AssignFlocks();
		UpdateBoidsPaths();
		Draw();
		Window.display();
	}
}
void Canvas::Draw()
{
	BoidShape bs = BoidShape(12);
	for(auto& boid : SpawnedBoids)
	{
		auto pos = boid.GetPosition();
		if(pos.x >= Window.getSize().x)
			pos.x = 1;
		else if(pos.x <= 0)
			pos.x = Window.getSize().x - 1;

		if(pos.y >= Window.getSize().y)
			pos.y = 1;
		else if(pos.y <= 0)
			pos.y = Window.getSize().y - 1;
		boid.SetPosition(pos);

		bs.setPosition(pos);
		bs.setRotation(UIMath::ToDegrees(UIMath::GetAngle(boid.GetVelocity())) + 90);
		Window.draw(bs);
	}
	//DrawQTree();
}

void Canvas::UpdateBoidsPositions()
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
	{
		auto flock = QT.GetClosestTo(boid.GetPosition(), boid.GetPerception());
		for(size_t i = 0; i < flock.size(); i++)
			if(flock.at(i) == &boid)
			{
				flock.erase(flock.begin() + i);
				break;
			}

		boid.AssignToFlock(flock);
	}
}
void Canvas::UpdateBoidsPaths()
{
	for(auto& boid : SpawnedBoids)
		boid.CalculatePath();
}
void Canvas::DrawQTree()
{
	for(auto& qt : QT.GetSubsections())
	{
		float hw = (qt.GetLowerRightBound().x - qt.GetUpperLeftBound().x) / 2;
		float hh = (qt.GetLowerRightBound().y - qt.GetUpperLeftBound().y) / 2;

		sf::VertexArray horizontal(sf::LineStrip, 2);
		sf::VertexArray vertical(sf::LineStrip, 2);

		horizontal[0].position = qt.GetUpperLeftBound() + Vector2f(0,hh);
		horizontal[1].position = qt.GetLowerRightBound() + Vector2f(0,-hh);
		vertical[0].position = qt.GetUpperLeftBound() + Vector2f(hw,0);
		vertical[1].position = qt.GetLowerRightBound() + Vector2f(-hw,0);

		horizontal[0].color = Color(255,255,255,70);
		horizontal[1].color = Color(255,255,255,70);
		vertical[0].color = Color(255,255,255,70);
		vertical[1].color = Color(255,255,255,70);

		Window.draw(horizontal);
		Window.draw(vertical);
	}
}