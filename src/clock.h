#include <windows.h>

namespace
{
	const LPCTSTR winClassName	= TEXT("MCC");
	const int timerId			= 1001;
}

void RestartTimer(HWND hwnd);
void DrawClock(HWND hwnd);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);