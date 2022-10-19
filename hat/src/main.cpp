#include <iostream> 
#include "Input.h"
#include "Game.h"
#include <Windows.h>

int main()
{
	Input i;
	GameHad g;


	while (1)
	{

		system("cls");
		g.reactToKey(i.GetKey());
		g.update();
		Sleep(10);
	}
	
}
