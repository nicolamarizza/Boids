#ifndef UIMATH_HPP
#define UIMATH_HPP

#include <SFML/Graphics.hpp>

class UIMath
{
public:
	static float Magnitude(sf::Vector2f v);
	static sf::Vector2f SetMagnitude(sf::Vector2f v, float newMag);
	static sf::Vector2f Normalize(sf::Vector2f v);
	static float Distance(sf::Vector2f v0, sf::Vector2f v1);
	static float GetAngle(sf::Vector2f v);
	static float ToDegrees(float rad);
private:
	UIMath();
};
#endif