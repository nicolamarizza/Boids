#include <SFML/Graphics.hpp>
#include <LALG/Vector2.hpp>
#include <BoidShape.hpp>
#include <Boid.hpp>
#include <Canvas.hpp>

using namespace sf;
using namespace std;
int main()
{
	Canvas canvas(800, 800);
	for(int x = 0; x <= 800; x+=80)
		for(int y = 0; y <= 800; y+=80)
			canvas.SpawnBoidAt(x,y);

	canvas.Simulate();

	return 0;
}