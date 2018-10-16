#include "Vektor2d.h"

 sf::Vector2f Rotate(const sf::Vector2f &vec, float angleInDegrees)
{
	sf::Vector2f TempVector = vec;
	float temp = angleInDegrees * 3.14159f / 180.0f;
	float sin1 = sin(temp);
	float cos1 = cos(temp);
	float tempx = (TempVector.x * cos1) - (TempVector.y * sin1);
	TempVector.y = (TempVector.y * cos1) + (TempVector.x * sin1);
	TempVector.x = tempx;
	return TempVector;
}