
#include "Player.h"
#include <stdio.h>



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

		int i = 0;
		for (; i < snake.size(); i++)
		{
			if (snake[i].Vec != Dir::left)
			{
				if (i == 0)
				{
					snake[0].x++;
					snake[i].Vec = Dir::right;

				}
				else
				{
					switch (snake[i].Vec)
					{
					case Dir::down:
						snake[i].y = snake[i].y + 1; break;
					case Dir::up:
						snake[i].y = snake[i].y - 1; break;
						//case Dir::left:
							//snake[i].x = snake[i].x - 1; break;
					case Dir::right:
						snake[i].x = snake[i].x + 1; break;
					}
					if (snake[i].y == snake[i - 1].y)
					{
						snake[i].Vec = Dir::right;
					}
				}
			}
		}
	}
	else // LEFT "A"
	{
		
		int i = 0;
		for (; i < snake.size(); i++)
		{
			if (snake[i].Vec != Dir::right)
			{


				if (i == 0)
				{
					snake[0].x--;
					snake[i].Vec = Dir::left;
				}
				else
				{
					switch (snake[i].Vec)
					{
						case Dir::down:
							snake[i].y = snake[i].y + 1; break;
						case Dir::up:
							snake[i].y = snake[i].y - 1; break;
						case Dir::left:
							snake[i].x = snake[i].x - 1; break;
							//case Dir::right:
								//snake[i].x = snake[i].x + 1; break;
					}
					if (snake[i].y == snake[i - 1].y)
					{
						snake[i].Vec = Dir::left;
					}
				}
			}
		}
	}


}

void Player::SetPlayerY(bool Plus)
{
	if (Plus) // DOWN "S"
	{
		
		int i = 0;
		for (; i < snake.size(); i++)
		{
			if (snake[i].Vec != Dir::up)
			{


				if (i == 0)
				{
					snake[0].y++;
					snake[i].Vec = Dir::down;
				}
				else
				{
					switch (snake[i].Vec)
					{
					case Dir::down:
						snake[i].y = snake[i].y + 1; break;
						//case Dir::up:
							//snake[i].y = snake[i].y - 1; break;
					case Dir::left:
						snake[i].x = snake[i].x - 1; break;
					case Dir::right:
						snake[i].x = snake[i].x + 1; break;
					}
					if (snake[i].x == snake[i - 1].x)
					{
						snake[i].Vec = Dir::down;
					}
				}
			}
		}
		
	}
	else // UP "W"
	{
		
		int i = 0;
		for (; i < snake.size(); i++)
		{
			if (snake[i].Vec != Dir::down)
			{


				if (i == 0)
				{
					snake[0].y--;
					snake[i].Vec = Dir::up;
				}
				else
				{
					switch (snake[i].Vec)
					{
						//case Dir::down:
							//snake[i].y = snake[i].y + 1; break;
					case Dir::up:
						snake[i].y = snake[i].y - 1; break;
					case Dir::left:
						snake[i].x = snake[i].x - 1; break;
					case Dir::right:
						snake[i].x = snake[i].x + 1; break;
					}
					if (snake[i].x == snake[i - 1].x)
					{
						snake[i].Vec = Dir::up;
					}
				}
			}
		}
		
	}
}

int Player::ReturnLenght()
{
	return snake.size();
}



