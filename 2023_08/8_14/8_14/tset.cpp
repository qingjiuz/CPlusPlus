#pragma once
#include<iostream>
using namespace std;

#include"Date.h"

void TestDate()
{
	//Date d1(2023, 8, 14);
	//Date d2 = d1;			// 本质上还是拷贝重构函数

	//Date d3(2023, 8, 14);
	//Date d4;
	//d4 = d3;				// 这种还是使用了运算符重载
	//d3.Print();
	//d4.Print();

	//Date d1(2023, 8, 14);
	//Date d2(2023, 8, 14);

	//cout << (d1 < d2) << endl;
	//cout << (d1 <= d2) << endl;
	//cout << (d1 == d2) << endl;

	//Date d1(2023, 8, 14);
	//Date d2(2023, 9, 14);

	//cout << (d2 > d1) << endl;
	//cout << (d2 >= d1) << endl;
	//cout << (d1 >= d2) << endl;
	//cout << (d1 != d2) << endl;

	//Date d1(2023, 8, 14);
	//Date d2;
	////d2 = d1 + 365;
	////d2.Print();
	////d2 += 10;
	////d2.Print();

	//d2 = d1 - 100;
	//d2.Print();
	//d2 -= 10;
	//d2.Print();

	//Date d1(2023, 8, 1);
	//Date d2;
	
	//d2 = d1++;
	//d2.Print();
	//d2 = ++d1;
	//d2.Print();

	//d2 = d1--;
	//d2.Print();
	//d2 = --d1;
	//d2.Print();

	//Date d1(2023, 8, 14);
	//d1 += -100;
	//d1.Print();

}

void TestDate2()
{
	Date d1(2023, 5, 5);
	Date d2(1930, 10, 1);

	cout << (d1 - d2) << endl;
	cout << (d2 - d1) << endl;

}

int main()
{
	TestDate2();
	
	return 0;
}
