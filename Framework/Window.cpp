#include "framework.h"
#include "Window.h"


//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//  PURPOSE:  Processes messages for the main window.
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
	case WM_SIZE:
	{

	}
	case WM_CLOSE:
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}		
	default:
	{
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}		
	}

	return 0;
}
