#pragma once

class Window
{
public:
	struct WindowDesc
	{
		wstring WindowName;
		HINSTANCE Instance;
		HWND Handle;
		float Width;
		float Height;
		bool bVsync = true;
		bool bFullScreen = false;
		D3DXCOLOR BackgroundColor;
	};
public:	
	static Window* Get();

private:
	static void Create();
	static void Delete();	

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	static class IExecute* mainExecute;
};