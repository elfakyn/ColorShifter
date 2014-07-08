#pragma once

#include <Windows.h>
#include <iostream>
#include "colorTools.h"
#include "dllTools.h"

int loadDwmDll(HRESULT (WINAPI *&setDwmColors) (DwmColor *color, UINT unknown),
	HRESULT (WINAPI *&getDwmColors) (DwmColor *color))
{
	HMODULE hlib = LoadLibrary("dwmapi.dll"); // load the Window Manager API

	if (!hlib) {
		std::cerr << "Could not load dwmapi.dll" << std::endl;
		return 0;
	}
	*(FARPROC *)&getDwmColors = GetProcAddress(hlib, (LPCSTR)127);
	*(FARPROC *)&setDwmColors = GetProcAddress(hlib, (LPCSTR)131);

	return 1;
}