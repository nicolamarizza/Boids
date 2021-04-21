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
private:
	sf::Vector2f Position;
};

#endif