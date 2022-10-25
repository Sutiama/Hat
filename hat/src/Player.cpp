
#include "Player.h"
#include <stdio.h>
#include <stack>
#include <string>

Player::Player()
{
	lenght = 0;
	snake.push_back({ 10, 10, Dir::down});
	lenght++;
	increaseLenght();
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

		snake[0].x++;
		snake[0].Vec = Dir::right;

		Move();

	}
	else // LEFT "A"
	{
		if (snake[0].Vec == Dir::right) return;

		snake[0].x--;
		snake[0].Vec = Dir::left;

		Move();
		
	}


}

void Player::SetPlayerY(bool Plus)
{
	if (Plus) // DOWN "S"
	{
		if (snake[0].Vec == Dir::up) return;

		snake[0].y++;
		snake[0].Vec = Dir::down;

		Move();
	}
	else // UP "W"
	{
		if (snake[0].Vec == Dir::down) return;

		snake[0].y--;
		snake[0].Vec = Dir::up;

		Move();
	}
}

int Player::ReturnLenght()
{
	return snake.size();
}

//std::pair<float, float> Player::GetHeadPostion()
//{
//	return { snake[0].x, snake[0].y };
//}

void Player::Move()
{
	std::stack<Dir> changes;
	changes.push(Dir::null);
	for (size_t i = 1; i < snake.size(); i++)
	{
		if(snake[i].Vec != snake[i - 1].Vec)
			changes.push(snake[i - 1].Vec);
		else
			changes.push(Dir::null);
	}
	for (size_t i = snake.size(); i > 1; i--)
	{
		if (changes.top() != Dir::null)
			snake[i-1].Vec = changes.top();
		changes.pop();
	}

	for (size_t i = 1; i < snake.size(); i++)
	{
		switch (snake[i].Vec)
		{
		case Dir::down:  snake[i].y++; break;
		case Dir::left:  snake[i].x--; break;
		case Dir::right: snake[i].x++; break;
		case Dir::up:    snake[i].y--; break;
		}
	}
}
