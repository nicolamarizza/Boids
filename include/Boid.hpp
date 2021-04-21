#ifndef BOID_HPP
#define BOID_HPP

#include <SFML/Graphics.hpp>

class Boid
{
public:	
	Boid();
	Boid(float perception = 40, sf::Vector2f pos = sf::Vector2f(0,0));

	float GetPerception();
	sf::Vector2f GetPosition();
	sf::Vector2f GetVelocity();
	sf::Vector2f GetAcceleration();
	void SetPosition(sf::Vector2f position);
	void SetVelocity(sf::Vector2f velocity);
	void SetAcceleration(sf::Vector2f acceleration);
	void Update(float elapsedSeconds);
	void AssignToFlock(std::vector<Boid*> p_boids);
	void CalculatePath();
private:
	sf::Vector2f Separation();
	sf::Vector2f Cohesion();
	sf::Vector2f Alignment();

	float Perception;
	sf::Vector2f Position;
	sf::Vector2f Velocity = sf::Vector2f(0,0);
	sf::Vector2f Acceleration = sf::Vector2f(0,0);
	std::vector<Boid*> Flock;
	bool CatchingUp {false};

};

#endif