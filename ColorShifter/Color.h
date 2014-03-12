#ifndef COLOR_H
#define COLOR_H

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