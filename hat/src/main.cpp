
#include "Input.h"
#include "Game.h"
#include <Windows.h>

#include <crtdbg.h>  

#include "ConsoleRenderer.h"
#include "OpenGLRenderer.h"
#include "OpenGLContext.h"

#include "Window.h"

#include <memory> 



int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Input input;
	GameHad game;
	OpenGLRenderer renderer;
	Window* pWindow = new Window();
	bool running = true;
	srand(time(NULL));
	OpenGLContext context(pWindow);

	context.MakeContextCurrent();

	while (running)
	{
		//renderer.clear({ 1.0,0.0,1.0,1.0 });
		glClearColor(1.0, 0.5, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		if (!pWindow->ProcessMessages())
		{
			running = false;
		}

		//game.reactToKey(input.GetKey());

		//game.update(1);
		

		//renderer.draw2D(game.MapString(),game.width,game.height);
		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.5f, 0.5f);
		glVertex2f(-0.5f, -0.5f);
		glColor3f(0.9f, 0.1f, 0.9f);
		glVertex2f(0.0f, 0.5f);
		glColor3f(0.1f, 0.3f, 0.6f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		
		context.Swap();
		Sleep(100);
	}

	delete pWindow;

	return 0;
}
