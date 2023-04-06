#include "clock.h"

void RestartTimer(HWND hwnd)
{
	SetTimer(hwnd, timerId, 1000, NULL);
}

void DrawClock(HWND hwnd)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	GetClientRect(hwnd, &rect);
	InvalidateRect(hwnd, &rect, true);

	hdc			= BeginPaint(hwnd, &ps);
	int lfh		= -MulDiv(36, GetDeviceCaps(hdc, LOGPIXELSY), 72);
	HFONT font	= CreateFont(lfh, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				ANTIALIASED_QUALITY, 0, TEXT("Arial"));
	
	SelectObject(hdc, font);
	SetTextColor(hdc, RGB(200, 20, 20));
	SetBkMode(hdc, TRANSPARENT);
	SetTextAlign(hdc, TA_CENTER);

	TCHAR time[32];
	SYSTEMTIME st;
	GetLocalTime(&st);
	GetTimeFormat(LOCALE_SYSTEM_DEFAULT, 0, &st, NULL, time, 32);

	const int cx	= (rect.right - rect.left) / 2;
	const int cy	= (rect.bottom - rect.top + lfh) / 2;
	TextOut(hdc, cx, cy, time, lstrlen(time));

	EndPaint(hwnd, &ps);
}