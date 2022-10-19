#include "Game.h"
#include <stdio.h>


void GameHad::update()
{
	map = "";

	int a = 20;
	for (int i = 0;i<a*20;i++)
	{
		if (i < a || i % a == 0 || i % a == 19 || i > a*a-a)
		{
			map += " *";
		}
		else if(drawPlayer(i % a, i/a ))
		{
			map += " #";
		}
		else
		{
			map += "  ";
		}

		if (i % a == a-1)
		{
			map += "\n";
		}
	}

	printf("%s", map.c_str());
}

bool GameHad::drawPlayer(float x,float y)
{
	
	if (Px == x && Py == y)
		return 1;
	else
		return 0;
	
}

void GameHad::reactToKey(char key)
{
	if (key == 'w') Py--;
	if (key == 's') Py++;
	if (key == 'a') Px--;
	if (key == 'd') Px++;	
}


