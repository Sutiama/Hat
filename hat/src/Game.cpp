
#include "Game.h"
#include <stdio.h>
#include <iostream>



void GameHad::update()
{
	m_Map = "";
	
	m_Player.MoveOnUpdate();

	a = 20;
	for (int i = 0;i<a*20;i++)
	{
		m_X = i % a;
		m_Y = i / a;

		BorderCollision();
		CreateFruit();
		
		FruitCollision();
		

		if (i < a || i % a == 0 || i % a == a-1 || i > a*a-a)
		{
			m_Map += " *";
		}
		else if(ShouldDrawPlayer())
		{
			m_Map += " #";
		}
		else if (Fruit(m_X,m_Y))
		{
			m_Map += " +";
		}
		else 
		{
			m_Map += "  ";
		}

		if (i % a == a-1)
		{
			m_Map += "\n";
		}
		
		
		
		
	}

	//printf("%s", m_Map.c_str());
	
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
		/*if (key == 'w') Px--;
		if (key == 's') Px++;
		if (key == 'a') Py--;
		if (key == 'd') Py++;*/		
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

void GameHad::BorderCollision()
{

	if (a < m_Player.GetPositions()[0].first+2 || a < m_Player.GetPositions()[0].second+2 || 0 > m_Player.GetPositions()[0].first - 1 || 0 > m_Player.GetPositions()[0].second - 1)
	{
		exit(1);
	}
}

bool GameHad::Fruit(float x, float y)
{
	if (x == m_FruitX && y == m_FruitY)
	{
		return true;
	}
	return false;
}

void GameHad::CreateFruit()
{
	int i = 0;
	//do
	//{
	if (FruitCount == 0)
		{
			i++;
			m_FruitX = rand() % 19 + 1;
			m_FruitY = rand() % 19 + 1;
			FruitCount = 1;
		}
	//} while(m_FruitX == m_Player.GetPositions()[i].first)
	
}



void GameHad::FruitCollision()
{
	if (m_FruitX == m_Player.GetPositions()[0].first && m_FruitY == m_Player.GetPositions()[0].second)
	{
		m_Player.increaseLenght();
		FruitCount=0;
	}

}

const std::string& GameHad::MapString()
{
	return m_Map;
}