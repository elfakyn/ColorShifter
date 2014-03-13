#ifndef DWMPARAMS
#define DWMPARAMS

typedef struct { // DwmColorizationParameters
	int color;
	int afterglow;
	int colorBalance;
	int afterglowBalance;
	int blurBalance;
	int glassReflectionIntensity;
	int opaqueBlend;
} DwmColorizationParameters;

#endif

#ifndef COLOR
#define COLOR

class Color {
private:
	int argb[4];
	int balance; // colorBalance
public:
	Color();

	void SetARGB(int[]); // Alpha Red Green Blue
	int* GetARGB();

	void SetAHSV(int[]); // Alpha Hue Saturation Value
	int* GetAHSV();

	void SetMerged(int); // ARGB channels merged into an int 0xAARRGGBB
	int GetMerged();

	void SetBalance(int);
	int GetBalance();
};

#endif

Color interpolate(Color, Color, double);

extern int* AHSVfromARGB(int*);
extern int* ARGBfromAHSV(int*);

Color importColor(DwmColorizationParameters);
DwmColorizationParameters exportColor(Color);
