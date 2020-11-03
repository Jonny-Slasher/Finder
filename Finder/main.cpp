#include"Finder.h"
#include"PrintInterfase.h"
#include<Windows.h>

//this is the main function 
//for successfully work use c++17 code standart
int main() {
	std::cout << "Welcome to QuickSearch app\n";
	std::cout << "There are three simple steps\n";
	std::cout << "1 - t is enter correct path to desirable folder\n";
	std::cout << "2 - nd is enter name, type of file\n";
	std::cout << "3 - Press enter\n";
	//Sleep(1500);
	//system("cls");
	PrintInterfase* print = new ConsolePrint;

	std::wstring wpath;
	bool flag = 0;
	FileEngine search;

	search.SetPath(wpath);
	do {
		std::cout << "Enter Path\n";
		std::getline(std::wcin, wpath);
		search.SetPath(wpath);
		flag = search.IsExist();
		if (flag == 0) {
			std::cout << "Path does not exists try again \n";
		}
	} while (flag != 1);

	std::cout << "What file or extension do you want to search\n";
	std::string searchname;
	std::getline(std::cin, searchname);
	searchname = TransformToLowerCase(searchname);
	search.SetSearchName(searchname);

	search.RecursiveSearch();
	search.Print(print);
	std::cout << "Was found - " << search.GetId() << " elements\n";
	delete print;
	return 0;

}
