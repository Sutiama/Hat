#pragma once
#include "Window.h"
#include <Windows.h>



class OpenGLContext
{ 
public:
	OpenGLContext();
	void Create(Window* window);
	void MakeContextCurrent();
	void SwapChain();

private:
	HDC m_HDC;
	HGLRC m_HGLRC;
};