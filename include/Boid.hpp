#ifndef BOID_HPP
#define BOID_HPP

#include <SFML/Graphics.hpp>

class Boid
{
public:	
	Boid();
	Boid(float x, float y);
	Boid(sf::Vector2f pos);

	sf::Vector2f GetPosition();
	void Update(float elapsedSeconds);
private:
	float Perception {60};
	sf::Vector2f Separation(float elapsedSeconds);
	sf::Vector2f Position;
};

#endif