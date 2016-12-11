#include "Algorithm.h";

Matrix HeroPosition(4,Row(1));

void InitPositionData()
{
	HeroPosition[0][0] = 0;
	HeroPosition[1][0] = 0;
	HeroPosition[2][0] = 0;
	HeroPosition[3][0] = 1;
}
void SetHeroPosition(Matrix Position)
{
	HeroPosition[0][0] = Position[0][0];
	HeroPosition[1][0] = Position[1][0];
	HeroPosition[2][0] = Position[2][0];
	HeroPosition[3][0] = Position[3][0];
}
Matrix GetHeroPosition()
{
	return HeroPosition;
}