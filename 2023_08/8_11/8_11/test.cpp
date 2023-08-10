#include"fun.h"
#include<iostream>
using namespace std;

//inline int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int sum = Add(10, 20);
//	cout << sum << endl;
//
//	return 0;
//}

//错误的用法
//void test(auto a)
//{
//
//}

//int main()
//{
//	//int a = 0;
//	//double b = 1.23;
//
//	//auto aa = a;
//	//auto bb = b;
//
//	//int a = 10;
//	//auto b = &a;
//	//auto* c = &a;
//	//auto& d = a;
//
//	//auto x = 1, y = 0;
//	//auto z = 1.1, f = 0;	//错误的用法
//
//	int a[] = { 1,2,3 };
//	//auto b[] = { 1,2,3 };	//错误的用法
//
//	return 0;
//}

int main()
{
	int a[] = { 7,5,4,2,6,8,9,1,3 };
	for (auto n : a)
	{
		cout << n << " ";
	}

	return 0;
}

