
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
	OpenGLContext context;
	Window* pWindow = new Window();
	bool running = true;
	srand(time(NULL));

	
	//context.Create(pWindow);
	HDC hdc = nullptr;
	hdc = GetDC(pWindow->GetHandle());

	PIXELFORMATDESCRIPTOR pfd = { 0 };
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.cColorBits = 24;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;

	int index = ChoosePixelFormat(hdc, &pfd);

	PIXELFORMATDESCRIPTOR rpfd = { 0 };

	DescribePixelFormat(hdc, index, sizeof(PIXELFORMATDESCRIPTOR), &rpfd);

	SetPixelFormat(hdc, index, &rpfd);
	HGLRC hglrc = wglCreateContext(hdc);

	
	context.Create(pWindow);
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
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		
		context.SwapChain();
	}

	delete pWindow;

	return 0;
}
