#pragma once
class GameStatus
{
public:
	GameStatus();
	void setStage(int stage);
	void setIsGameOver(bool state);
	void setIsPlayerWin(bool state);
	void setIsOpeningAnimation(bool state);
	void setIsLostAnimation(bool state);
	void setIsWinAnimation(bool state);
	void setAnimation(bool state);
	int getStage();
	bool getAnimation();
	bool getIsGameOver();
	bool getIsPlayerWin();
	bool getIsOpeningAnimation();
	bool getIsLostAnimation();
	bool getIsWinAnimation();
	~GameStatus();
private:
	int Stage;
	bool isGameOver;
	bool isPlayerWin;
	bool isOpeningAnimation;
	bool isLostAnimation;
	bool isWinAnimation;
	bool isAnimation;
};

