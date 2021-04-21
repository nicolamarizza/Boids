#include <Boid.hpp>
using namespace sf;

Boid::Boid() : 
	Perception{40},
	Position(Vector2f(0,0)),
	Flock{std::vector<Boid*>()}
{}
Boid::Boid(float perception, Vector2f pos) : 
	Perception{perception},
	Position{pos},
	Flock{std::vector<Boid*>()}
{}
float Boid::GetPerception() {return Perception;}
Vector2f Boid::GetPosition() {return Position;}
void Boid::Update(float elapsedSeconds)
{
	/*
	Vector2f acceleration = Vector2f(0,0);
	acceleration += Separation(elapsedSeconds);*/
}
void Boid::AssignToFlock(std::vector<Boid*> flock) {Flock = flock;}
/*
Vector2f Boid::Separation(float elapsedSeconds)
{

}*/
