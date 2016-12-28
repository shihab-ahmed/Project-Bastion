#pragma once
class Animation
{
public:
	Animation();
	void angleXUpdate(float val);
	void angleYUpdate(float val);
	void camYUpdate();
	void Opening();
	float givePosY();
	void Win();
	~Animation();
private:
	float angleX;
	float angleY;
	float angleZ;
	float camX;
	float camY;
	float camZ;
	float posY;
	float playerReachedOpeningCamera;
	bool  openingState1;
	bool  openingState2;
	bool  openingState3;
	bool  openingState4;
	bool  openingState5;
	bool  openingState6;
	bool  openingState7;

	bool  winState1;
	bool  winState2;
	bool  winState3;
	bool  winState4;
	bool  winState5;
	bool  winState6;
	bool  winState7;
};

