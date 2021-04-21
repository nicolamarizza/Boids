#include <BoidShape.hpp>
using namespace sf;

BoidShape::BoidShape(int length) : Length{length} 
{ 
	update(); 
}
std::size_t BoidShape::getPointCount() const
{
	return (size_t)3;
}
Vector2f BoidShape::getPoint(std::size_t index) const
{
	if(index == 0)
		return Vector2f(0,-(Length * 2 / 3));

	int len3 = Length/3;
	if(index == 1)
		return Vector2f(len3, len3);
	
	return Vector2f(-len3, len3);

}