#include <array>
#include "colorTools.h"

#define MIN3(x, y, z) ((x) < (y) ? ((x) < (z) ? (x) : (z)) : ((y) < (z) ? (y) : (z))) 
#define MAX3(x, y, z) ((x) > (y) ? ((x) > (z) ? (x) : (z)) : ((y) > (z) ? (y) : (z)))
#define ABS(x) ((x) > 0 ? (x) : (0 - x))

int* AHSVfromARGB(int argb[])
{
	int* ahsv = new int[4];
	std::fill(ahsv, ahsv+4, 0);

	// Calculate alpha
	ahsv[0] = argb[0];
	
	// Calculate value
	ahsv[3] = MAX3(argb[1], argb[2], argb[3]);

	if (ahsv[3] == 0) { // Black
		return ahsv;
	}

	// Calculate chroma (used for saturation and hue)
	int chroma = ahsv[3] - MIN3(argb[1], argb[2], argb[3]);

	// Calculate saturation
	ahsv[2] = 255 * chroma / ahsv[3];

	if (ahsv[2] == 0) { // Grey
		return ahsv;
	}

	// Calculate hue
	if (ahsv[3] == argb[1]) {
		ahsv[1] = 0 + 43 * (argb[2] - argb[3]) / chroma;
	} else if (ahsv[3] == argb[2]) {
		ahsv[1] = 85 + 43 * (argb[3] - argb[1]) / chroma;
	} else {
		ahsv[1] = 170 + 43 * (argb[1] - argb[2]) / chroma;
	}
	
	return ahsv;
}

int* ARGBfromAHSV(int ahsv[])
{
	int* argb = new int[4];
	std::fill(argb, argb+4, 0);

	// Calculate alpha
	argb[0] = ahsv[0];

	// Calculate chroma and second largest component
	int chroma = ahsv[3] * ahsv[2] / 255;
	int second = (ahsv[1] - ahsv[1] / 85 * 85) * 6 - 255; // Intermediate value for efficiency
	second = 255 - ABS(second);

	// Determine which component is chroma and which is second by region
	switch (ahsv[1] * 2 / 85) {
	case 0:
	case 6:
		argb[1] = chroma; argb[2] = second;
		break;
	case 1:
		argb[1] = second; argb[2] = chroma;
		break;
	case 2:
		argb[2] = chroma; argb[3] = second;
		break;
	case 3:
		argb[2] = second; argb[3] = chroma;
		break;
	case 4:
		argb[3] = chroma; argb[1] = second;
		break;
	case 5:
		argb[3] = second; argb[1] = chroma;
		break;
	}

	// Add minimum to each component to get final values
	int minimum = ahsv[3] - chroma;

	argb[1] = argb[1] + minimum;
	argb[2] = argb[2] + minimum;
	argb[3] = argb[3] + minimum;

	return argb;
}