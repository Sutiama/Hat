
#include "Player.h"
#include <stdio.h>
#include <stack>
#include "Game.H"

GameHad g;


Player::Player()
{
	lenght = 0;
	snake.push_back({ 10, 10, Dir::down});
	lenght++;
	increaseLenght();
	increaseLenght();
}

std::vector<std::pair<float, float>> Player::GetPositions()
{
	std::vector<std::pair<float, float>> Positions;

	for (std::size_t i = 0; i < snake.size(); i++)
	{
		Positions.push_back({ snake[i].x , snake[i].y });
	}
	return Positions;
}

int Player::increaseLenght()
{
	float cx = 0;
	float cy = 0;

	switch (snake[lenght-1].Vec)
	{
	case Dir::left:
			cx = snake[lenght - 1].x + 1;
			cy = snake[lenght - 1].y;
		break;
	case Dir::right:
			cx = snake[lenght - 1].x - 1;
			cy = snake[lenght - 1].y;
		break;
	case Dir::up:
			cx = snake[lenght - 1].x;
			cy = snake[lenght - 1].y + 1;
		break;
	case Dir::down:
			cx = snake[lenght - 1].x;
			cy = snake[lenght - 1].y - 1;
		break;
	}
	

	snake.push_back({ cx,cy,snake[lenght - 1].Vec });

	lenght++;

	return lenght;
}


void Player::SetPlayerX(bool Plus)
{
	if (Plus) // RIGHT "D"
	{
		if (snake[0].Vec == Dir::left) return;
		if (PlayerCollision(snake[0].x + 1, snake[0].y)) exit(1);
		Move();
		snake[0].x++;
	
		snake[0].Vec = Dir::right;
	}
	else // LEFT "A"
	{
		if (snake[0].Vec == Dir::right) return;
		if (PlayerCollision(snake[0].x - 1, snake[0].y)) exit(1);
		Move();
		snake[0].x--;
		
		snake[0].Vec = Dir::left;
	}


}

void Player::SetPlayerY(bool Plus)
{
	if (Plus) // DOWN "S"
	{
		if (snake[0].Vec == Dir::up) return;
		if (PlayerCollision(snake[0].x, snake[0].y + 1)) exit(1);
		Move();
		snake[0].y++;
		
		snake[0].Vec = Dir::down;
	}
	else // UP "W"
	{
		if (snake[0].Vec == Dir::down) return;
		if (PlayerCollision(snake[0].x, snake[0].y - 1)) exit(1);
		Move();
		snake[0].y--;
		
		snake[0].Vec = Dir::up;
	}
}

int Player::ReturnLenght()
{
	return snake.size();
}



void Player::Move()
{
	
	float X = snake[1].x, X2;
	float Y = snake[1].y,Y2;

	snake[1].x = snake[0].x;
	snake[1].y = snake[0].y;
	
	
	
	for (size_t i = 2; i < snake.size(); i++)
	{
		X2 = snake[i].x;
		Y2 = snake[i].y;	
		
		snake[i].x = X;
		snake[i].y = Y;

		X = X2;
		Y = Y2;
		/*switch (snake[i].Vec)
		{
			case Dir::down:  snake[i].y++; break;
			case Dir::left:  snake[i].x--; break;
			case Dir::right: snake[i].x++; break;
			case Dir::up:    snake[i].y--; break;
		}

		snake[1].Vec = snake[0].Vec;
	
		*/
		
		
		
		
	}
	
}

bool Player::PlayerCollision(float x,float y)
{
	
	for (size_t i = 0; i < snake.size(); i++)
	{
		if (snake[i].x == x && snake[i].y == y)
		{
			return true;
		}
	}
	return false;
}


