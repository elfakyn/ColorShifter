#include <fstream>
#include <iostream>
#include "colorTools.h"
#include "dllTools.h"
#include "exitCodes.h"

int main()
{
	HRESULT(WINAPI *getDwmStatus) (BOOL *ok);
	HRESULT(WINAPI *setDwmColors) (DwmColor *color, UINT unknown);
	HRESULT(WINAPI *getDwmColors) (DwmColor *color);

	if (!loadDwmDll(getDwmStatus, setDwmColors, getDwmColors)) {
		exit(EXIT_DLL_LOAD_FAIL);
	}

	BOOL ok;
	getDwmStatus(&ok);
	if (!ok) {
		exit(EXIT_COMPOSITION_DISABLED);
	}

	std::ifstream readColor;
	readColor.open("colorscheme.txt");

	Color color1, color2;
	unsigned int steps, wait_ms, currentColorValue;
	DwmColor crt = { 0 };

	readColor >> std::hex >> currentColorValue;
	color1.SetMerged(currentColorValue);
	crt = exportColor(color1);
	setDwmColors(&crt, 0);


	while (!readColor.eof()) {
		readColor >> std::hex >> currentColorValue >> std::dec >> steps >> wait_ms;
		color2.SetMerged(currentColorValue);
		for (int i = 0; i < steps; i++) {
			crt = exportColor(interpolate(color1, color2, i * 1.0 / steps));
			setDwmColors(&crt, 0);
			Sleep(wait_ms);
		}

		color1 = color2;
	}

	exit(EXIT_OK);
}