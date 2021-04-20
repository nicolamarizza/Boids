#include <SFML/Graphics.hpp>

class BoidShape : public sf::Shape
{
public :
    explicit BoidShape(int length);
    virtual std::size_t getPointCount() const;
    virtual sf::Vector2f getPoint(std::size_t index) const;

private :
    int Length;
};