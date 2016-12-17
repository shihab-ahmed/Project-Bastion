#pragma once
class PlazmaBall
{
public:
	PlazmaBall(float positionX, float positionY, float positionZ, float velX, float velZ, float initialRotation, float type);
	void drawPlazmaBall(float type);
	void move();
	void flagAsDead();
	bool isDead();
	float givePosX();
	float givePosZ();
	float getType();
	~PlazmaBall();
private:
	float speedX, speedZ;
	float originalSpeedX, originalSpeedZ;
	float posX, posY, posZ;
	float type;
	int remainingLife;
};

