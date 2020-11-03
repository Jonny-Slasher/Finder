#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include"PrintInterfase.h"


namespace fs = std::filesystem;

//function that transforms string to lower case
std::string TransformToLowerCase(std::string to_lower);

//basic class 
class FileEngine {
private:

	std::wstring wpath;
	fs::path path;
	std::string searchname;//variable for searching 
	static int counter;
	int ID;
	std::vector<std::string>fileslist;//variable to keep and show match elements

public:
	
	FileEngine() {}
	FileEngine(std::wstring wpath);

	~FileEngine() {

	}
	//set path from users input
	void SetPath(std::wstring twpath);

	//set string to search from users input
	void SetSearchName(std::string ts_name);

	//Getter to show lists of pathes
	std::vector<std::string> GetFileList()const;

	//Getter to get quantity of mathes
	int GetId()const;

	//functios to define is path true
	bool IsExist();

	//recursive search matches in dir and subdirs
	void RecursiveSearch();

	//Print data to console 
	virtual void Print(PrintInterfase* p);

};



