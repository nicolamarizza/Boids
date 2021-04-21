#ifndef UIMATH_HPP
#define UIMATH_HPP

#include <SFML/Graphics.hpp>

class UIMath
{
public:
	static float Magnitude(sf::Vector2f v);
	static float Distance(sf::Vector2f v0, sf::Vector2f v1);

private:
	UIMath();
};

#endif