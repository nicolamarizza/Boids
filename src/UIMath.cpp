#include <UIMath.hpp>
#include <cmath>
using namespace sf;

float UIMath::Magnitude(Vector2f v)
{
	return sqrt(pow(v.x, 2) + pow(v.y, 2));
}
Vector2f UIMath::SetMagnitude(Vector2f v, float newMag)
{
	return Normalize(v) * newMag;
}
Vector2f UIMath::Normalize(Vector2f v)
{
	return v / UIMath::Magnitude(v);
}
float UIMath::Distance(Vector2f v0, Vector2f v1)
{
	return Magnitude(v0 - v1);
}
float UIMath::GetAngle(Vector2f v)
{
	return atan2(v.y, v.x);
}
float UIMath::ToDegrees(float rad)
{
	return rad * 180 / M_PI;
}