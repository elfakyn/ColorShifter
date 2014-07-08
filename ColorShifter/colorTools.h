#pragma once

typedef struct {
	int color;
	int afterglow;
	int colorBalance;
	int afterglowBalance;
	int blurBalance;
	int glassReflectionIntensity;
	int opaqueBlend;
} DwmColor;

typedef struct {
	unsigned char w;
	unsigned char x;
	unsigned char y;
	unsigned char z;
} uchar4;

class Color {
private:
	uchar4 argb;
	unsigned char balance; // colorBalance
public:
	Color();

	void SetARGB(uchar4); // Alpha Red Green Blue
	uchar4 GetARGB();

	void SetAHSV(uchar4); // Alpha Hue Saturation Value
	uchar4 GetAHSV();

	void SetMerged(int); // ARGB channels merged into an int 0xAARRGGBB
	int GetMerged();

	void SetBalance(unsigned char);
	unsigned char GetBalance();
};

Color interpolate(Color, Color, double);

uchar4 AHSVfromARGB(uchar4);
uchar4 ARGBfromAHSV(uchar4);

Color importColor(DwmColor);
DwmColor exportColor(Color);
