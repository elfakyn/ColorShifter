#include "colorTools.h"
#include <iostream>
using namespace std;

Color::Color()
{
	uchar4 argb = { 0 };
	unsigned char balance = 0;
}

void Color::SetARGB(uchar4 argb_)
{
	argb = argb_;
}

uchar4 Color::GetARGB()
{
	return argb;
}

void Color::SetAHSV(uchar4 ahsv)
{
	argb = ARGBfromAHSV(ahsv);
}

uchar4 Color::GetAHSV()
{
	return AHSVfromARGB(argb);
}

void Color::SetMerged(int merged)
{
	argb.w = (unsigned char)((merged >> 24) & 0xFF);
	argb.x = (unsigned char)((merged >> 16) & 0xFF);
	argb.y = (unsigned char)((merged >> 8) & 0xFF);
	argb.z = (unsigned char)(merged & 0xFF);
}

int Color::GetMerged()
{
	return (argb.w << 24) |
		(argb.x << 16) |
		(argb.y << 8) |
		argb.z;
}

void Color::SetBalance(unsigned char balanceIn)
{
	balance = balanceIn;
}

unsigned char Color::GetBalance()
{
	return balance;
}
