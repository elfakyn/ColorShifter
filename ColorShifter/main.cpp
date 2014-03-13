#include <iostream>
#include <Windows.h>
#include "colorTools.h"
#include "transitionTools.h"
HMODULE hlib;
int main()
{
	hlib = LoadLibrary("dwmapi.dll"); // load the Window Manager API

	if (!hlib) {
		std::cerr << "Could not load dwmapi.dll" << std::endl;
		return -1;
	}
	*(FARPROC *)&DwmGetColorizationParameters = GetProcAddress(hlib, (LPCSTR)127);
	*(FARPROC *)&DwmSetColorizationParameters = GetProcAddress(hlib, (LPCSTR)131);

	Color color1, color2;
	color1.SetMerged(0xFFFF0000);
	color1.SetBalance(50);
	color2.SetMerged(0xFF0000FF);
	color2.SetBalance(50);
	int steps = 100;
	int wait_ms = 30;
	DwmColorizationParameters crt = { 0 };
	while (1) {
		for (int i = 0; i < steps; i++) {
			crt = exportColor(interpolate(color1, color2, i * 1.0 / steps));
			DwmSetColorizationParameters(&crt, 0);
			Sleep(wait_ms);
		}
		for (int i = 0; i < steps; i++) {
			crt = exportColor(interpolate(color2, color1, i * 1.0 / steps));
			DwmSetColorizationParameters(&crt, 0);
			Sleep(wait_ms);
		}
	}

//	singleTransition(color1, color2, 100, 500, DwmSetColorizationParameters);
}
