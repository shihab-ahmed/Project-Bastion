#pragma once
class StatusUI
{
public:
	StatusUI();
	void drawPlayerStatus(int health, int shield, int score);
	void drawGameStatus();
	~StatusUI();
};

