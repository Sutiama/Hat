#pragma once

#include "Player.h"
#include <string>
#include <time.h>

class GameHad
{
private:
	std::string m_Map;
	Player m_Player;
	
	float m_X, m_Y;
	float m_FruitX, m_FruitY;

	int a, FruitCount = 0;

	bool ShouldDrawPlayer();
	int move();
	
public:
	void update();
	void reactToKey(char key);
	
	
	bool IsOnPosition();

	void BorderCollision();

	bool Fruit(float x, float y);
	void CreateFruit();
	float ReturnFruitX();
	float ReturnFruitY();
	void FruitCollision();
};