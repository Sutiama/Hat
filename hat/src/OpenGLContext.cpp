#include "OpenGLContext.h"

OpenGLContext::OpenGLContext(Window* window)
{
	hdc = GetDC(window->GetHandle());

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
}

void OpenGLContext::MakeContextCurrent()
{
	wglMakeCurrent(hdc, hglrc);
}

void OpenGLContext::Swap()
{
	SwapBuffers(hdc);
}