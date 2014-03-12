#include "colorTools.h"
#include "Color.h"

Color interpolate(Color color1, Color color2, float xvalue)
{
	int* ahsv1 = color1.GetAHSV();
	int* ahsv2 = color2.GetAHSV();
	int ahsvOut[4], balanceOut;

	for (int i = 0; i < 4; i++) {
		ahsvOut[i] = int((ahsv2[i] - ahsv1[i]) * xvalue + ahsv1[i]);
	}
	balanceOut = int((color2.GetBalance() - color1.GetBalance()) * xvalue + color1.GetBalance());

	Color colorOut;
	colorOut.SetAHSV(ahsvOut);
	colorOut.SetBalance(balanceOut);

	return colorOut;
}