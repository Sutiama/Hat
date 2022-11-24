#pragma once

#include <Windows.h>
#include <iostream>
#include <GL/GL.h>
#include "wingdi.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);



class Window
{
public:
	Window();
	~Window();

	bool ProcessMessages();
	
	
	HWND GetHandle();

	HGLRC createContext(Window* window, HDC hdc);
	void setContext(Window* window, HDC hdc, HGLRC hglrc);
private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;
	

	
};

