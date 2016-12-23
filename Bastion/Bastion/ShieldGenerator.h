#pragma once
class ShieldGenerator
{
public:
	ShieldGenerator(float positionX, float positionY, float positionZ, float initialRotation);
	void drawShield();
	~ShieldGenerator();
private:
	float posX, posY, posZ;
	float type;
	float rotation;
	float height, width, depth;
	int ShieldLife,Life;
	float ShieldRadius;
};

