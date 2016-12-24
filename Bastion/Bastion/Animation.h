#pragma once
class Animation
{
public:
	Animation();
	void angleXUpdate(float val);
	void angleYUpdate(float val);
	void camYUpdate();
	void Opening();
	~Animation();
private:
	float angleX;
	float angleY;
	float angleZ;
	float camX;
	float camY;
	float camZ;
	float playerReachedOpeningCamera;
	bool  openingState1;
	bool  openingState2;
	bool  openingState3;
	bool  openingState4;
	bool  openingState5;
	bool  openingState6;
	bool  openingState7;
};

