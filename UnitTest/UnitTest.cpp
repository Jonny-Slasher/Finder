#include "pch.h"
#include "CppUnitTest.h"
#include "../Finder/main.cpp"
#include"../Finder/Finder.cpp"
#include"../Finder/PrintInterfase.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(IsExists){
			fs::path p;
			fs::create_directory("D:/Test");
			FileEngine test;
			test.SetPath(L"D:/Test");
			
			bool flag = 0;
			flag = test.IsExist();
			Assert::AreEqual(true, flag);
			fs::remove("D:/Test");
		}
		TEST_METHOD(RecursiveSearch) 
		{
			int counter = 0;
			fs::create_directories("D:/testdir/1/2/a");
			FileEngine test;
			test.SetPath(L"D:/testdir");
			test.RecursiveSearch();
			counter = test.GetId();
			Assert::AreEqual(3, counter);
			fs::remove("D:/testdir/1/2/a");
		}
		TEST_METHOD(LowerCase)
		{ 
			std::string test;
			std::string test2("engine");
			test = TransformToLowerCase("EnGinE");
			Assert::AreEqual(test,test2 );
		}
	};
}
