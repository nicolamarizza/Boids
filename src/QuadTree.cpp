#include <QuadTree.hpp>
#include <UIMath.hpp>
#include <cmath>
using namespace sf;

QuadTree::QuadTree(Vector2f upperLeft, Vector2f lowerRight, size_t capacity) :
	Capacity{capacity},
	P_Boids(std::vector<Boid*>()),
	SubSections(std::vector<QuadTree>()),
	UpperLeft{upperLeft},
	LowerRight{lowerRight}
{

}
void QuadTree::InsertAt(sf::Vector2f pos, Boid* p_boid)
{
	if(!IsWithinBounds(pos))
		return;

	if(P_Boids.size() < Capacity)
	{
		P_Boids.push_back(p_boid);
		return;
	}

	if(SubSections.size() == 0)
	{
		float hw = (LowerRight.x - UpperLeft.x) / 2;
		float hh = (LowerRight.y - UpperLeft.y) / 2;

		SubSections.push_back(QuadTree(
			UpperLeft, 
			Vector2f(UpperLeft.x + hw, UpperLeft.y + hh), 
			Capacity));

		SubSections.push_back(QuadTree(
			Vector2f(UpperLeft.x + hw, UpperLeft.y), 
			Vector2f(LowerRight.x, UpperLeft.y + hh), 
			Capacity));
			
		SubSections.push_back(QuadTree(
			Vector2f(UpperLeft.x + hw, UpperLeft.y + hh), 
			LowerRight, 
			Capacity));

		SubSections.push_back(QuadTree(
			Vector2f(UpperLeft.x, UpperLeft.y + hh), 
			Vector2f(UpperLeft.x + hw, LowerRight.y), 
			Capacity));
	}

	for(auto& subsection : SubSections)
		subsection.InsertAt(pos, p_boid);
}
std::vector<Boid*> QuadTree::GetClosestTo(sf::Vector2f pos, float distance)
{
	std::vector<Boid*> queryResult = std::vector<Boid*>();
	GetClosestToRecursive(queryResult, pos, distance);
	return queryResult;
}
std::vector<Boid*> QuadTree::GetAll()
{
	return GetClosestTo(GetCenter(), UIMath::Distance(UpperLeft, LowerRight));
}
void QuadTree::Clear()
{
	SubSections.clear();
	P_Boids.clear();
}

sf::Vector2f QuadTree::GetCenter()
{
	return UpperLeft + (LowerRight - UpperLeft) / 2.f;
}
void QuadTree::GetClosestToRecursive(std::vector<Boid*>& cumulativeResult, sf::Vector2f pos, float distance)
{
	if(!Intersects(pos, distance))
		return;

	for(auto& subSection : SubSections)
		subSection.GetClosestToRecursive(cumulativeResult, pos, distance);

	for(auto& p_boid : P_Boids)
		if(UIMath::Distance(p_boid->GetPosition(), pos) <= distance)
			cumulativeResult.push_back(p_boid);
}
bool QuadTree::Intersects(sf::Vector2f pos, float distance)
{
	return !(
		pos.x - distance > LowerRight.x ||
		pos.x + distance < UpperLeft.x ||
		pos.y + distance < UpperLeft.y ||
		pos.y - distance > LowerRight.y
	);
}
bool QuadTree::IsWithinBounds(sf::Vector2f pos)
{
	return (
		pos.x >= UpperLeft.x &&
		pos.x <= LowerRight.x &&
		pos.y >= UpperLeft.y &&
		pos.y <= LowerRight.y
	);
}
