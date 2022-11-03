
#include "Input.h"
#include "Game.h"
#include <Windows.h>

#include <stdlib.h>
#include <crtdbg.h>  

#include "Renderer.h"
#include <memory> 

int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Input i;
	GameHad g;
	ConsoleRenderer Cr;
	srand(time(NULL));
	

	while (1)
	{
		system("cls");
		
		g.reactToKey(i.GetKey());
		g.update();
		
		Cr.Draw2D(g.MapString());
		Sleep(500);
	}


	return 0;
}
