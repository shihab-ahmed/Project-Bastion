#pragma once
class StatusUI
{
public:
	StatusUI();
	void drawPlayerStatus(int health, int shield, int score);
	void drawGameStatus();
	void drawGameObjective();
	void drawWelomce();
	void flagAsDead(bool state);
	bool getIsDead();
	~StatusUI();
private:
	float remainLife;
	bool  isDead;
};

