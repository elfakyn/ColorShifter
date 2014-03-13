#include <array>
#include "colorTools.h"

Color::Color()
{
	std::array<int, 4> argb = { 0 };
	balance = 100;
}

void Color::SetARGB(int *argbIn)
{
	std::copy(argbIn, argbIn + 4, argb);
}

int* Color::GetARGB()
{
	return argb;
}

void Color::SetAHSV(int *ahsv)
{
	int* argbIn = ARGBfromAHSV(ahsv);
	std::copy(argbIn, argbIn + 4, argb);
}

int* Color::GetAHSV()
{
	return AHSVfromARGB(argb);
}

void Color::SetMerged(int merged)
{
	argb[0] = (merged >> 24) & 0xFF;
	argb[1] = (merged >> 16) & 0xFF;
	argb[2] = (merged >> 8) & 0xFF;
	argb[3] = merged & 0xFF;
}

int Color::GetMerged()
{
	return (argb[0] << 24) | (argb[1] << 16) | (argb[2] << 8) | argb[3];
}

void Color::SetBalance(int balanceIn)
{
	balance = balanceIn;
}

int Color::GetBalance()
{
	return balance;
}
