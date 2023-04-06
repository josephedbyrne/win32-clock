#include "clock.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	LPMINMAXINFO lpMMI;

	switch (msg)
	{
		case WM_CREATE:
			RestartTimer(hwnd);
			break;

		case WM_TIMER:
			if (wParam == timerId)
			{
				RestartTimer(hwnd);
				SendMessage(hwnd, WM_PAINT, 0, 0);
			}

			break;

		case WM_SIZE:
		case WM_PAINT:
			DrawClock(hwnd);
			break;

		case WM_GETMINMAXINFO:
			lpMMI	= (LPMINMAXINFO) lParam;
			lpMMI->ptMinTrackSize.x	= 400;
			lpMMI->ptMinTrackSize.y	= 200;
			break;

		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	return 0;
}