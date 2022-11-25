#include "OpenGLContext.h"

OpenGLContext::OpenGLContext() :
	m_HDC(nullptr),
	m_HGLRC(nullptr)
{
}

void OpenGLContext::Create(Window* window)
{
	m_HDC = GetDC(window->GetHandle());

	PIXELFORMATDESCRIPTOR pfd = { 0 };
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.cColorBits = 24;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;

	int index = ChoosePixelFormat(m_HDC, &pfd);

	PIXELFORMATDESCRIPTOR rpfd = { 0 };

	DescribePixelFormat(m_HDC, index, sizeof(PIXELFORMATDESCRIPTOR), &rpfd);

	SetPixelFormat(m_HDC, index, &rpfd);
	m_HGLRC = wglCreateContext(m_HDC);
}

void OpenGLContext::MakeContextCurrent()
{
	wglMakeCurrent(m_HDC, m_HGLRC);
}

void OpenGLContext::SwapChain()
{
	SwapBuffers(m_HDC);
}