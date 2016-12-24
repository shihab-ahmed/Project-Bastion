#pragma once
class GameStatus
{
public:
	GameStatus();
	void setStage(int stage);
	void setIsGameOver(bool state);
	void setIsPlayerWin(bool state);
	int getStage();
	bool getIsGameOver();
	bool getIsPlayerWin();
	~GameStatus();
private:
	int Stage;
	bool isGameOver;
	bool isPlayerWin;
};

