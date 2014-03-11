#include <iostream>
#include <Windows.h>
#include "dwmParams.h"

int main2()
{
	HMODULE hlib = LoadLibrary("dwmapi.dll"); // load the Window Manager API

	if (!hlib) {
		std::cerr << "Could not load dwmapi.dll" << std::endl;
		return -1;
	}

	typedef VOID(*DwmSetColorizationParametersProc) (DwmColorizationParameters *);
	typedef VOID(*DwmGetColorizationParametersProc) (DwmColorizationParameters *);

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

	DwmColorizationParameters currentColors = { 0xffff0000, 0, 30, 0, 0, 0, 0 };
	DwmSetColorizationParameters(&currentColors);

	return 0;
}