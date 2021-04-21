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
	sf::RenderWindow Window;
	QuadTree QT;
};

#endif