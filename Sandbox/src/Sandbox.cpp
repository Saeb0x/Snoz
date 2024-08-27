#include <iostream>

namespace Snoz
{
	__declspec(dllimport) void PrintHello();
}

int main()
{
	Snoz::PrintHello();
	std::cin.get();
}