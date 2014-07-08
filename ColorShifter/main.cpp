#include <fstream>
#include <iostream>
#include "colorTools.h"
#include "dllTools.h"

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

	std::ifstream readColor;
	readColor.open("colorscheme.txt");

	Color color1, color2;
	unsigned int steps, wait_ms, currentColorValue;
	DwmColor crt = { 0 };

	readColor >> std::hex >> currentColorValue;
	std::cout << std::hex << currentColorValue << std::endl;
	color1.SetMerged(currentColorValue);
	crt = exportColor(color1);
	DwmSetColorizationParameters(&crt, 0);


	while (!readColor.eof()) {
		readColor >> std::hex >> currentColorValue >> std::dec >> steps >> wait_ms;
		color2.SetMerged(currentColorValue);
		for (int i = 0; i < steps; i++) {
			crt = exportColor(interpolate(color1, color2, i * 1.0 / steps));
			DwmSetColorizationParameters(&crt, 0);
			Sleep(wait_ms);
		}

		color1 = color2;
	}

	return 0;

	//	singleTransition(color1, color2, 100, 500, DwmSetColorizationParameters);
}