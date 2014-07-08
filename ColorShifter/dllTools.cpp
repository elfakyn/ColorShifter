/*#include <Windows.h>
#include <iostream>
#include "colorTools.h"
#include "dllTools.h"

int loadDwmDll(HRESULT f_)
{
	HRESULT *(WINAPI *DwmSetColorizationParameters) (DwmColor *color, UINT unknown);
	HRESULT *(WINAPI *DwmGetColorizationParameters) (DwmColor *color);

	HMODULE hlib = LoadLibrary("dwmapi.dll"); // load the Window Manager API

	if (!hlib) {
		std::cerr << "Could not load dwmapi.dll" << std::endl;
		return 0;
	}
	*(FARPROC *)&DwmGetColorizationParameters = GetProcAddress(hlib, (LPCSTR)127);
	*(FARPROC *)&DwmSetColorizationParameters = GetProcAddress(hlib, (LPCSTR)131);

	return 1;
}*/