#pragma once
class Building
{
public:

	Building(float positionX, float positionZ, float height, float Width, float Depth);

	~Building();
	void BuildingA();
	void drawSelf();
	float givePosX();
	float givePosZ();
	float giveHeight();
	float giveWidth();
	float giveDepth();
private:
	float posX, posZ,height,width,depth;
};
