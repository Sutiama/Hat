
#include "Game.h"
#include <stdio.h>


Player player;

void GameHad::update()
{
	m_Map = "";


	int a = 20;
	for (int i = 0;i<a*20;i++)
	{
		m_X = i % a;
		m_Y = i / a;


		if (i < a || i % a == 0 || i % a == a-1 || i > a*a-a)
		{
			m_Map += " *";
		}
		else if(ShouldDrawPlayer())
		{
			m_Map += " #";
		}
		else
		{
			m_Map += "  ";
		}

		if (i % a == a-1)
		{
			m_Map += "\n";
		}
		
		
			//printf("%f ", x);
			//printf("%f \n", y);	
		
	}

	printf("%s", m_Map.c_str());
	
}

bool GameHad::ShouldDrawPlayer()
{
	if (IsOnPosition())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GameHad::reactToKey(char key)
{
		//if (key == 'w') Px--;
		//if (key == 's') Px++;
		//if (key == 'a') Py--;
		//if (key == 'd') Py++;
		
	switch (key)
	{
		case 'w':
			m_Player.SetPlayerY(0);
		break;
		case 's':
			m_Player.SetPlayerY(1);
		break;
		case 'a':
			m_Player.SetPlayerX(0);
		break;
		case 'd':
			m_Player.SetPlayerX(1);
		break;
	}

	
}

bool GameHad::IsOnPosition()
{
		
	for(int i = 0; i < m_Player.GetPositions().size();i++)
	{
		if (m_X == m_Player.GetPositions()[i].first && 
		    m_Y == m_Player.GetPositions()[i].second   )
		{
			return true;
		}
	}
	return false;
}
