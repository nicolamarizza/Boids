#include <Boid.hpp>
#include <UIMath.hpp>
#include <cmath>

using namespace sf;

constexpr float SEPARATION_DISTANCE{15};
constexpr float SEPARATION_FORCE_MULTIPLIER{1};
constexpr float COHESION_DISTANCE{40};
constexpr float COHESION_FORCE_MULTIPLIER{1};
constexpr float ALIGNMENT_DIFFERENCE{10};
constexpr float ALIGNMENT_FORCE_MULTIPLIER{6};
constexpr float LOWEST_SPEED{40};
constexpr float HIGHEST_SPEED{120};


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
sf::Vector2f Boid::GetVelocity() {return Velocity;}
sf::Vector2f Boid::GetAcceleration() {return Acceleration;}
void Boid::SetPosition(sf::Vector2f position) {Position = position;}
void Boid::SetVelocity(sf::Vector2f velocity) {Velocity = velocity;}
void Boid::SetAcceleration(sf::Vector2f acceleration) {Acceleration = acceleration;}
void Boid::Update(float elapsedSeconds)
{
	Position = Position + Velocity * elapsedSeconds + 0.5f * (float)pow(elapsedSeconds, 2) * Acceleration;
	Velocity = Velocity + elapsedSeconds * Acceleration;
	if(UIMath::Magnitude(Velocity) < LOWEST_SPEED)
		Velocity = UIMath::SetMagnitude(Velocity, LOWEST_SPEED);
}
void Boid::AssignToFlock(std::vector<Boid*> flock) {Flock = flock;}
void Boid::CalculatePath()
{
	if(Flock.size() == 0)
		return;

	Acceleration = Vector2f(0,0);
	Acceleration += Separation();
	Acceleration += Cohesion();
	Acceleration += Alignment();

	if(UIMath::Magnitude(Velocity) < LOWEST_SPEED)
		CatchingUp = true;
	else if(UIMath::Magnitude(Velocity) > HIGHEST_SPEED)
		CatchingUp = false;

	if(CatchingUp)
		Acceleration += UIMath::SetMagnitude(Velocity, HIGHEST_SPEED) - Velocity;
}

Vector2f Boid::Separation()
{
	Vector2f acceleration;
	Boid* p_closest = Flock.at(0);

	for(size_t i = 1; i < Flock.size(); i++)
		if(UIMath::Distance(Position, Flock.at(i)->Position) < UIMath::Distance(Position, p_closest->Position))
			p_closest = Flock.at(i);

	acceleration = Position - p_closest->Position;
	if(UIMath::Magnitude(acceleration) < SEPARATION_DISTANCE)
		return acceleration * SEPARATION_FORCE_MULTIPLIER;

	return Vector2f(0,0);
}
sf::Vector2f Boid::Cohesion()
{
	Vector2f acceleration = Vector2f(0,0);
	for(auto p_boid : Flock)
		acceleration += p_boid->Position;
	
	acceleration /= (float)Flock.size();
	acceleration -= Position;

	if(UIMath::Magnitude(acceleration) > COHESION_DISTANCE)
		return acceleration * COHESION_FORCE_MULTIPLIER;

	return Vector2f(0,0);
}
sf::Vector2f Boid::Alignment()
{
	Vector2f acceleration = Vector2f(0,0);
	for(auto p_boid : Flock)
		acceleration += p_boid->Velocity;

	acceleration /= (float)Flock.size();
	acceleration -= Velocity;

	if(UIMath::Magnitude(acceleration) > ALIGNMENT_DIFFERENCE)
		return acceleration * ALIGNMENT_FORCE_MULTIPLIER;

	return Vector2f(0,0);
}