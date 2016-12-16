#include "Definition.h"
#include "PlazmaBall.h"
#pragma once
class Player
{
public:
	Player(float positionX, float positionZ, float initialRotation);
	int BeltRotation();
	void DrawHeroMiddleBody();
	void damage(int amount);
	bool isHitBy(PlazmaBall * theBullet);
	float playerLegRotation();
	void WalkingState(bool isWalk);
	void accelerate(bool directionIsForward);
	float givePosX();
	float givePosZ();
	void rotate(bool directionIsPositive);
	void move();
	float giveSpeed();
	float giveTurretRotation();
	float giveTurretRotationSpeed();
	float giveSpeedX();
	float giveSpeedZ();
	float giveRotation();
	float giveRotationSpeed();
	float playerWidth();
	float PlayerHeight();
	float PlayerDepth();
	void rotateTurret(float amount);
	bool fire();
	bool canMoveTo(float newX, float newZ);
	void DrawPlayer();
	~Player();
private:
	int Beltangle;
	float speed;
	float posX, posZ;
	float speedX, speedZ;
	float rotation, rotationSpeed;
	float width, height, depth;
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
	bool isWalking=false;
	float legRotation = 0.0f;
	bool legRotationMaxReached = false;
};

