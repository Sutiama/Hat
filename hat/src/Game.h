#pragma once

#include <string>

class GameHad
{
private:
	std::string map;
	float Px = 10, Py = 10;

	bool drawPlayer(float x,float y);
	int move();
	
public:
	void update();
	void reactToKey(char key);


};