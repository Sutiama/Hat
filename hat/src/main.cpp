
#include "Input.h"
#include "Game.h"
#include <Windows.h>

#include <stdlib.h>
#include <crtdbg.h>  

#include <memory> 

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Input i;
	GameHad g;

	while (1)
	{
		system("cls");
		
		g.reactToKey(i.GetKey());
		g.update();
		
		Sleep(300);
	}

	return 0;
}
