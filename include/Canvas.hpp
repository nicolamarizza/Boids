#ifndef CANVAS_HPP
#define CANVAS_HPP

#include<SFML/Graphics.hpp>
#include <QuadTree.hpp>

class Canvas
{
public:
	Canvas(int width, int height);
	void SpawnBoidAt(int x, int y);
	void Simulate();
	void Draw();
private:
	void UpdateBoidsPositions();
	void RefreshQtree();
	void AssignFlocks();
	void UpdateBoidsPaths();
	void DrawQTree();
	std::vector<Boid> SpawnedBoids = std::vector<Boid>();
	sf::RenderWindow Window;
	QuadTree QT;
	sf::Clock LastRefresh;
};

#endif