/*#include "Windows.h"
#include "colorTools.h"
#include "transitionTools.h"
#include <iostream>

void singleTransition(Color color1, Color color2, int steps, int wait_ms, DwmSetColorizationParametersProc setColor)
{
	DwmColorizationParameters crt = { 0 };
	for (int i = 0; i < steps; i++) {
		crt = exportColor(interpolate(color1, color2, i * 1.0 / steps));
		setColor(&crt, 0);
		Sleep(wait_ms);
	}
}
*/