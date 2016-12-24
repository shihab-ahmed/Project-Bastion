#pragma once
class Building
{
public:
	Building(float positionX, float positionZ, float height, float Width, float Depth, float rotation, float type);

	~Building();
	void BuildingA();
	float getType();
	void drawSelf(float type);
	void BuildingB();
	float givePosX();
	float givePosZ();
	float giveHeight();
	float giveWidth();
	float giveDepth();
private:
	float posX, posZ,height,width,depth,rotation,type;
};
