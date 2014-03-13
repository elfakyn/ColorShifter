#include "colorTools.h"
#include <iostream>

Color interpolate(Color color1, Color color2, double xvalue)
{
	int* ahsv1 = color1.GetAHSV();
	int* ahsv2 = color2.GetAHSV();
	int ahsvOut[4], balanceOut;

	for (int i = 0; i < 4; i++) {
		ahsvOut[i] = int(xvalue * (ahsv2[i] - ahsv1[i]) + 1.0 * ahsv1[i]);
//		std::cout << std::hex << ahsvOut[i] << std::endl;
	}
	balanceOut = int((color2.GetBalance() - color1.GetBalance()) * xvalue + color1.GetBalance());

	Color colorOut;
	colorOut.SetAHSV(ahsvOut);
	colorOut.SetBalance(balanceOut);

	return colorOut;
}
