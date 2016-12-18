#include "CollisionDetection.h"
using namespace std;

float distanceBetween(float x1, float z1, float x2, float z2) 
{
	return sqrt((x2 - x1)*(x2 - x1) + (z2 - z1)*(z2 - z1));
}
bool isClipped(float x1, float z1)
{
	
	if ((-82 <= x1) && (x1 <= -58) && ( 58 <= z1) && (z1 <=  82))return true;
	if ((-82 <= x1) && (x1 <= -58) && (-82 <= z1) && (z1 <= -60))return true;
	if (( 58 <= x1) && (x1 <=  82) && (-82 <= z1) && (z1 <= -58))return true;
	if (( 58 <= x1) && (x1 <=  82) && ( 58 <= z1) && (z1 <=  82))return true;

	if ((-42 <= x1) && (x1 <=  -8) && (-82 <= z1) && (z1 <= -58))return true;
	if ((-42 <= x1) && (x1 <=  -8) && ( 58 <= z1) && (z1 <=  82))return true;
	if ((  8 <= x1) && (x1 <=  42) && (-82 <= z1) && (z1 <= -58))return true;
	if ((  8 <= x1) && (x1 <=  42) && ( 58 <= z1) && (z1 <=  82))return true;

	if ((-82 <= x1) && (x1 <= -58) && (  8 <= z1) && (z1 <= 42))return true;
	if ((-82 <= x1) && (x1 <= -58) && (-42 <= z1) && (z1 <= -8))return true;
	if (( 58 <= x1) && (x1 <=  82) && (  8 <= z1) && (z1 <= 42))return true;
	if (( 58 <= x1) && (x1 <=  82) && (-42 <= z1) && (z1 <= -8))return true;

	if ((  8 <= x1) && (x1 <=  42) && ( -42 <= z1) && (z1 <=  -8))return true;
	if ((-42 <= x1) && (x1 <=  -8) && ( -42 <= z1) && (z1 <=  -8))return true;
	if ((-42 <= x1) && (x1 <=  -8) && (   8 <= z1) && (z1 <=   42))return true;
	if (( 8 <= x1) && (x1 <=   42) && (   8 <= z1) && (z1 <=   42))return true;

	else
	{
		return false;
	}
	
}


