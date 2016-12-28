#pragma once
class Environment
{
public:
	Environment();
	void makeGrid(float size);
	void drawStreet();
	void snowMan();
	void tree();
	void Block(float posX, float posZ, float Rotation);
	float SolarAnimationUpdate();
	void bench();
	void globe();
	void solarSystem();
	void Park(float x, float y, float z, float h, float w, float d);
	void PortalArea(float posX, float posZ, float rotation);
	void Blocades();
	void Sea(float size);
	void groundFloor(float size);
	~Environment();
	void DrawEnvironment();
private:
	float solarAngle;
};

