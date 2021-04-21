#include <UIMath.hpp>
#include <cmath>
using namespace sf;

float UIMath::Magnitude(Vector2f v)
{
	return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

float UIMath::Distance(Vector2f v0, Vector2f v1)
{
	return Magnitude(v0 - v1);
}