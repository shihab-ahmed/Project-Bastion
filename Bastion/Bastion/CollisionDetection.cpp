#include "CollisionDetection.h"


float distanceBetween(float x1, float z1, float x2, float z2) 
{
	return sqrt((x2 - x1)*(x2 - x1) + (z2 - z1)*(z2 - z1));
}


