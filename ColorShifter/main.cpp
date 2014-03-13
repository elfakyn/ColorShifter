#include <iostream>
#include <Windows.h>
#include "colorTools.h"
#include "transitionTools.h"

int main()
{
	HMODULE hlib = LoadLibrary("dwmapi.dll"); // load the Window Manager API

	if (!hlib) {
		std::cerr << "Could not load dwmapi.dll" << std::endl;
		return -1;
	}

	typedef void(*DwmSetColorizationParametersProc) (DwmColorizationParameters *);
	typedef void(*DwmGetColorizationParametersProc) (DwmColorizationParameters *);

	DwmGetColorizationParametersProc DwmGetColorizationParameters =
		(DwmGetColorizationParametersProc)GetProcAddress(hlib, (LPCSTR)127); // Microsoft calls it DwmGetColorizationParameters
	if (DwmGetColorizationParameters == NULL) {
		std::cerr << "Could not load DwmGetColorizationParameters" << std::endl;
	}
	
	DwmSetColorizationParametersProc DwmSetColorizationParameters =
		(DwmSetColorizationParametersProc)GetProcAddress(hlib, (LPCSTR)131); // Microsoft calls it DwmSetColorizationParameters
	if (DwmSetColorizationParameters == NULL) {
		std::cerr << "Could not load DwmSetColorizationParameters" << std::endl;
	}

	Color color1, color2;
	color1.SetMerged(0xFFFF0000);
	color1.SetBalance(50);
	color2.SetMerged(0xFF0000FF);
	color2.SetBalance(50);

	singleTransition(color1, color2, 100, 300, DwmSetColorizationParameters);

	return 0;
}
