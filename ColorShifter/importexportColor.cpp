#include "colorTools.h"
#include <iostream>
Color importColor(DwmColorizationParameters in)
{
	Color out;
	out.SetMerged(in.color);
	out.SetBalance(in.colorBalance);
	return out;
}

DwmColorizationParameters exportColor(Color in)
{
	DwmColorizationParameters out = { 0 }; // Most fields unused
//	std::cout << "ieC " << std::hex << in.GetMerged() << std::endl;
	out.color = in.GetMerged();
//	std::cout << "ieC " << std::hex << in.GetBalance() << std::endl;
	out.colorBalance = in.GetBalance();
	return out;
}
