#include "colorTools.h"
#include "Color.h"

Color interpolate(Color color1, Color color2, float xvalue)
{
	int* argb1 = color1.GetARGB();
	int* argb2 = color2.GetARGB();
	int argbOut[4];

	for (int i = 0; i < 4; i++) {
		argbOut[i] = int((argb2[i] - argb1[i]) * xvalue + argb1[i]);
	}

	Color colorOut;
	colorOut.SetARGB(argbOut);
	return colorOut;
}