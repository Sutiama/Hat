
#include "Input.h"
#include "Game.h"
#include <Windows.h>

#include <stdlib.h>
#include <crtdbg.h>  

#include "Renderer.h"
#include "Window.h"
#include <memory> 



int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Input i;
	GameHad g;
	ConsoleRenderer Cr;
	Window* pWindow = new Window();
	bool running = true;
	srand(time(NULL));
	
	
	
	while (running)
	{
		system("cls");
		g.reactToKey(i.GetKey());
		//g.update();
		if (!pWindow->ProcessMessages())
		{
			running = false;
		}
		
		//render
		//Cr.Draw2D(g.MapString());
		
		Sleep(100);
	}

	//delete pWindow;

	return 0;
}
