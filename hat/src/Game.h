#pragma once

#include "Player.h"
#include <string>

class GameHad
{
private:
	std::string m_Map;
	Player m_Player;
	
	float m_X, m_Y;

	bool ShouldDrawPlayer();
	int move();
	
public:
	void update();
	void reactToKey(char key);
	
	
	bool IsOnPosition();

	

};