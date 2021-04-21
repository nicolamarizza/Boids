#include <Boid.hpp>
using namespace sf;

Boid::Boid() : Position(Vector2f(0,0)) {}
Boid::Boid(float x, float y) : Position(Vector2f(x, y)) {}
Boid::Boid(Vector2f pos) : Position{pos} {}
Vector2f Boid::GetPosition() {return Position;}
void Boid::Update(float elapsedSeconds)
{
	Vector2f acceleration = Vector2f(0,0);
	acceleration += Separation(elapsedSeconds);
}

Vector2f Boid::Separation(float elapsedSeconds)
{
	
}
