#pragma once
class Collectable
{
public:
	~Collectable();
	Collectable(float positionX, float positionY, float positionZ, float initialRotation, float type);
	bool isHitBy(Collectable * collectable);
	float getRotation();
	void drawCollectable(float type);
	void flagAsDead();
	bool isDead();
	float givePosX();
	float givePosZ();
	float getType();
private:
	float speedX, speedZ;
	float posX, posY, posZ;
	float type;
	float rotation;
	float height, width, depth;
	int remainingLife;
};

