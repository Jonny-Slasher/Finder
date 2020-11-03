#pragma once
#include<iostream>
#include<vector>
#include<string>
class PrintInterfase {
	public:
		virtual void Print(std::vector<std::string>data) = 0;
};

class ConsolePrint :public PrintInterfase {
	public:
		virtual void Print(std::vector<std::string>data);
};
