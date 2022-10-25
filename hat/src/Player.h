
#pragma once
#include <vector>

enum Dir
{
	left,
	right,
	up,
	down,
};

struct SnakePointData
{

	float x, y;
	Dir Vec;
};

class Player 
{
	private:
		int lenght = 2;
		//bool state;
		//float rychlost;
		std::vector<SnakePointData> snake;
		
		
		

	public:
		int increaseLenght();
		bool IsOnPosition();
		Player();

		std::vector<std::pair<float,float>> GetPositions();

		void SetPlayerX(bool PlusOrMinus);
		void SetPlayerY(bool PlusOrMinus);

		int ReturnLenght();
};