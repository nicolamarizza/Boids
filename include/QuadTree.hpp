#ifndef QUADTREE_HPP
#define QUADTREE_HPP

#include <SFML/Graphics.hpp>
#include <Boid.hpp>

class QuadTree
{
public:
	QuadTree(){}
	QuadTree(sf::Vector2f upperLeft, sf::Vector2f lowerRight, size_t capacity);

	void InsertAt(sf::Vector2f pos, Boid* p_boid);
	std::vector<Boid*> GetClosestTo(sf::Vector2f pos, float distance);
	std::vector<Boid*> GetAll();
	void Clear();
	std::vector<QuadTree> GetSubsections();
	sf::Vector2f GetUpperLeftBound();
	sf::Vector2f GetLowerRightBound();
private:
	sf::Vector2f GetCenter();
	void GetClosestToRecursive(std::vector<Boid*>& cumulativeResult, sf::Vector2f pos, float distance);
	bool Intersects(sf::Vector2f pos, float distance);
	bool IsWithinBounds(sf::Vector2f pos);
	void GetSubsectionsRecursive(std::vector<QuadTree>& cumulativeResult);

	size_t Capacity;
	std::vector<Boid*> P_Boids;
	std::vector<QuadTree> SubSections;
	sf::Vector2f UpperLeft;
	sf::Vector2f LowerRight;
};

#endif