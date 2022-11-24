#pragma once
#include "Window.h"
#include <Windows.h>



class OpenGLContext
{ 
public:
	OpenGLContext(Window* window);
	void MakeContextCurrent();
	void Swap();
private:
	HDC hdc;
	HGLRC hglrc;
};