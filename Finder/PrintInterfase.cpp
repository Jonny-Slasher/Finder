#include "PrintInterfase.h"

void ConsolePrint::Print(std::vector<std::string> data)
{
	std::cout << "console print\n";
	for (auto it = data.begin(); it != data.end(); it++) {
		std::cout << *it << std::endl;
	}
}