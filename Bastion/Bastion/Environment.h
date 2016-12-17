#pragma once
class Environment
{
public:
	Environment();
	void makeGrid(float size);
	void drawStreet();
	void drawStreetLamp();
	void groundFloor(float size);
	~Environment();
	void DrawEnvironment();
};

