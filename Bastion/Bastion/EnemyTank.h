#pragma once
#include "PlazmaBall.h"
class EnemyTank
{
public:
	EnemyTank(float positionX, float positionZ, float initialRotation);
	~EnemyTank();
	void TankTire();
	float getMiddleBodyDistance(float val, float body);
	bool canMoveTo(float newX, float newZ);
	void move();
	void rotateTurret(float amount);
	void turnTurretToward(float newAngle);
	bool fire();
	void runAI();
	void rotate(bool directionIsPositive);
	void accelerate(bool directionIsForward);
	void turnToward(float newAngle);
	float angleTo(float x, float z);
	float getWheelRotation();
	void damage(int amount);
	bool isHitBy(PlazmaBall * theBullet);
	void WalkingState(bool isWalk);
	float playerWidth();
	float PlayerHeight();
	float PlayerDepth();
	bool isDead();
	float givePosX();
	float givePosZ();
	float giveSpeedX();
	float giveSpeedZ();
	float giveRotation();
	void DrawTankType1();
	float giveRotationSpeed();
	float giveTurretRotation();
	float giveTurretRotationSpeed();
	float giveHealth();
private:
	float wheelRotation=0.0f;
	bool isWalking = true;
	float width, height, depth;
	float speed;
	float posX, posZ;
	float speedX, speedZ;
	float rotation, rotationSpeed;
	float turretRotation, turretRotationSpeed;
	int health;
	int reloadTime, reloadCounter;
	bool canSeePlayer;
	float sightRange;
	int sightCounter;
	bool isAimed;
	float destinX, destinZ;
	float lastSightingX, lastSightingZ;
	bool atDestination;
	float recoilStrength, recoilDistance, curRecoilForce;
	float boostSpeed, boostPower;
	int shieldStrength;
	float shieldOpacity;
	float originalRotation;
	bool turnLeft=false;
	
};

