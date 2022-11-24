#include "OpenGLRenderer.h"


void OpenGLRenderer::switchBuffers(HDC hdc)
{
	SwapBuffers(hdc);
}