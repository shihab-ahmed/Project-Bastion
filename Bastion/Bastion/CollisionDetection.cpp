#include "CollisionDetection.h"
using namespace std;

float distanceBetween(float x1, float z1, float x2, float z2) 
{
	return sqrt((x2 - x1)*(x2 - x1) + (z2 - z1)*(z2 - z1));
}
bool isClipped(float x1, float z1)
{
	
	if ((-80 <= x1) && (x1 <= -60) && ( 60 <= z1) && (z1 <=  80))return true;
	if ((-80 <= x1) && (x1 <= -60) && (-80 <= z1) && (z1 <= -60))return true;
	if (( 60 <= x1) && (x1 <=  80) && (-80 <= z1) && (z1 <= -60))return true;
	if (( 60 <= x1) && (x1 <=  80) && ( 60 <= z1) && (z1 <=  80))return true;

	if ((-40 <= x1) && (x1 <= -10) && (-80 <= z1) && (z1 <= -60))return true;
	if ((-40 <= x1) && (x1 <= -10) && ( 60 <= z1) && (z1 <=  80))return true;	
	if (( 10 <= x1) && (x1 <=  40) && (-80 <= z1) && (z1 <= -60))return true;
	if (( 10 <= x1) && (x1 <=  40) && ( 60 <= z1) && (z1 <=  80))return true;

	if ((-80 <= x1) && (x1 <= -60) && ( 10 <= z1) && (z1 <=  40))return true;
	if ((-80 <= x1) && (x1 <= -60) && (-40 <= z1) && (z1 <= -10))return true;
	if (( 60 <= x1) && (x1 <=  80) && ( 10 <= z1) && (z1 <=  40))return true;
	if (( 60 <= x1) && (x1 <=  80) && (-40 <= z1) && (z1 <= -10))return true;


	else
	{
		return false;
	}
	
}


