#include "pch.h"
#include"../Finder/Finder.cpp"
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

//TEST(DoesExist, IfExist) {
//	fs::path p;
//	fs::create_directory("D:/Test");
//	p = L"D:/Test";
//	bool flag = 0;
//	flag = is_exist(p);
//	ASSERT_EQ(true, flag);
//	fs::remove("D:/Test");
//}
//
//TEST(Iterator, howmany) {
//	int counter = 0;
//	fs::create_directories("D:/testdir/1/2/a");
//	for (auto& entry : fs::recursive_directory_iterator("D:/testdir")) {
//		counter++;
//	}
//	ASSERT_EQ(3, counter);
//	fs::remove("D:/testdir/1/2/a");
//}