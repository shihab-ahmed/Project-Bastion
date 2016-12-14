#pragma once
class PlazmaBall
{
public:
	PlazmaBall(float positionX, float positionY, float positionZ, float velX, float velZ, float initialRotation);
	void drawPlazmaBall();
	void move();
	void flagAsDead();
	bool isDead();
	float givePosX();
	float givePosZ();
	~PlazmaBall();
private:
	float speedX, speedZ;
	float originalSpeedX, originalSpeedZ;
	float posX, posY, posZ;
	int remainingLife;
};

