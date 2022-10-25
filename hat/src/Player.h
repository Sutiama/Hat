
#pragma once
#include <vector>

enum Dir
{
	null,
	left,
	right,
	up,
	down
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
		void Move();

		std::vector<std::pair<float,float>> GetPositions();

		void SetPlayerX(bool PlusOrMinus);
		void SetPlayerY(bool PlusOrMinus);
		
		

		int ReturnLenght();
		std::pair<float, float> GetHeadPostion();
}