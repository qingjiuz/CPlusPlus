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

// 流插入/流提取
void TestDate3()
{
	Date d1;
	Date d2;

	// 一般情况下，在类内部重载流插入和流提取的方式，不符合使用习惯
	//d1 << cout;
	// 像这样子的代码是可以正常编译和使用的

	// 其主要原因是在类内部定义的成员函数一般会被this指针占用了第一个参数
	// 导致cout/cin参数只能在第二位
	// 这种问题一般有两种解决方式
	// 1.在类内部再定义成员函数获取对象的值 --> 这种方法比较麻烦

	// 2.使用友元 --> 定义一个全局的函数
	cin >> d1 >> d2;
	cout << d1 << d2;
}

void TestDate4()
{
	Date d1(2023, 8, 14);
	d1.Print();		//d1.Print(Date* this);

	// 权限不能放大
	// 因此，为了保证const修饰的自定义变量可以正常使用
	// 一般会将不会修改this指针内的对象的函数加上const以修饰this指针
	// 加上const后变成 --> d2.Print(const Date* this) --> 权限的平移
	const Date d2(2023, 8, 15);
	d2.Print();		//不加const修饰，内部调用：d2.Print(Date* this);
	
	cout << (d2 + 100);

}


int main()
{
	TestDate4();
	
	return 0;
}
