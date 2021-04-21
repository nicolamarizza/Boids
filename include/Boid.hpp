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
	void Update(float elapsedSeconds);
	void AssignToFlock(std::vector<Boid*> p_boids);
private:
	sf::Vector2f Separation(float elapsedSeconds);

	float Perception;
	sf::Vector2f Position;
	std::vector<Boid*> Flock;
};

#endif