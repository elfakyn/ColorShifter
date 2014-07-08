#include "colorTools.h"

#define MAX2(x, y) ((x) > (y) ? (x) : (y))
#define MIN3(x, y, z) ((x) < (y) ? ((x) < (z) ? (x) : (z)) : ((y) < (z) ? (y) : (z)))
#define MAX3(x, y, z) ((x) > (y) ? ((x) > (z) ? (x) : (z)) : ((y) > (z) ? (y) : (z)))
#define ABS(x) ((x) > 0 ? (x) : (0 - (x)))
#define DIVCEIL(x, y) (((x) + (y) - 1) / (y)) // AHSVfromARGB rounds down, so ARGBfromAHSV will round up to compensate

int4 AHSVfromARGB(int4 argb)
{
	int4 ahsv = { 0 };
	// Calculate alpha
	ahsv.w = argb.w;

	// Calculate value
	ahsv.z = MAX3(argb.x, argb.y, argb.z);

	if (ahsv.z == 0) { // Black
		return ahsv;
	}

	// Calculate chroma (used for saturation and hue)
	int chroma = ahsv.z - MIN3(argb.x, argb.y, argb.z);

	// Calculate saturation
	ahsv.y = 255 * chroma / ahsv.z;

	if (ahsv.y == 0) { // Grey
		return ahsv;
	}

	// Calculate hue
	if (ahsv.z == argb.x) {
		ahsv.x = 43 * (argb.y - argb.z) / chroma;
		ahsv.x = ahsv.x >= 0 ? ahsv.x : 255 + ahsv.x;
	} else if (ahsv.z == argb.y) {
		ahsv.x = 85 + 43 * (argb.z - argb.x) / chroma;
	} else {
		ahsv.x = 170 + 43 * (argb.x - argb.y) / chroma;
	}

	return ahsv;
}

int4 ARGBfromAHSV(int4 ahsv)
{
	int4 argb = { 0 };
	// Calculate alpha
	argb.w = ahsv.w;

	// Calculate chroma (largest component) and second largest component
	int chroma = DIVCEIL(ahsv.z * ahsv.y, 255);

	int second = (ahsv.x % 85) * 6 - 255;
	second = 255 - ABS(second);
	second = DIVCEIL(second * chroma, 255);

	// Determine which component is chroma and which is second by region
	switch (ahsv.x * 2 / 85) {
	case 0:
	case 6:
		argb.x = chroma; argb.y = second;
		break;
	case 1:
		argb.x = second; argb.y = chroma;
		break;
	case 2:
		argb.y = chroma; argb.z = second;
		break;
	case 3:
		argb.y = second; argb.z = chroma;
		break;
	case 4:
		argb.z = chroma; argb.x = second;
		break;
	case 5:
		argb.z = second; argb.x = chroma;
		break;
	}

	// Add minimum (smallest component) to each component to get final values
	int minimum = ahsv.z - chroma;

	argb.x = argb.x + minimum;
	argb.y = argb.y + minimum;
	argb.z = argb.z + minimum;

	return argb;
}

#define INTERPOLATE(A1, A2, XVALUE) (int)((XVALUE) * ((A2) - (A1)) + 1.0 * (A1))

Color interpolate(Color color1, Color color2, double xvalue)
{
	int4 ahsv1 = color1.GetAHSV();//
	int4 ahsv2 = color2.GetAHSV();/////FIXME
	int4 ahsvOut;
	int balanceOut;

	ahsvOut.w = INTERPOLATE(ahsv1.w, ahsv2.w, xvalue);
	ahsvOut.x = INTERPOLATE(ahsv1.x, ahsv2.x, xvalue);
	ahsvOut.y = INTERPOLATE(ahsv1.y, ahsv2.y, xvalue);
	ahsvOut.z = INTERPOLATE(ahsv1.z, ahsv2.z, xvalue);
	balanceOut = INTERPOLATE(color1.GetBalance(), color2.GetBalance(), xvalue);

	Color colorOut;

	colorOut.SetAHSV(ahsvOut);///FIXME
	colorOut.SetBalance(0x64);

	return colorOut;
}

Color importColor(DwmColor in)
{
	Color out;
	out.SetMerged(in.color);
	out.SetBalance(in.colorBalance);
	return out;
}

DwmColor exportColor(Color in)
{
	DwmColor out = { 0 };
	out.color = in.GetMerged();
	out.colorBalance = in.GetBalance();
	return out;
}
