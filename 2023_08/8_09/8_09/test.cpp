#pragma once
#include<iostream>
using namespace std;

#include<time.h>


//struct A {
//
//	long a1;
//
//	short a2;
//
//	int a3;
//
//	int* a4;
//
//};
//
//struct B
//{};
//
//int main()
//{
//	//cout << sizeof(struct A) << endl;
//
//	//cout << sizeof(long) << endl;
//	//cout << sizeof(short) << endl;
//	//cout << sizeof(int) << endl;
//	//cout << sizeof(int*) << endl;
//
//	cout << sizeof(B) << endl;
//
//	return 0;
//}


//引用

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int& Count()
{
	static int a = 0;
	a++;
	return a;
}

//常引用
void TestConstRef()
{
	const int a = 10;
	//int& ra = a;		//因为a为常量，是常量的值是不能改变的
	const int& rra = a;

	//int& b = 10;		//因为10是常量，这里的问题是权限的放大
	const int& b = 10;

	double d = 3.14;
	//int& i = d;		//类型不同不能引用
	const int& ii = d;	//因为不同类型的转换之间会生成临时变量，临时变量具有常性

}

//返回值引用的错误使用
//int& Add(int x, int y)
//{
//	//在函数栈帧内定义的变量基本为临时变量
//	//在函数结束后栈帧会销毁，导致返回了类似野指针的变量
//	//因为在接收返回值之前，返回值会先存储在栈帧的临时变量上
//	//如果接受了这个临时变量就会出现访问野指针的问题
//	int sum = x + y;
//	return sum;
//}

//正确用法
int& Add(int x, int y)
{
	static int sum = x + y;
	return sum;
}


//int main()
//{
//	//int n1 = 10;
//	//int n2 = 20;
//	//int& a = n1;
//	//int& b = n1;
//	//b = n2;
//
//	//int a = 10;
//	//int b = 20;
//	//cout << "a = " << a << endl;
//	//cout << "b = " << b << endl;
//
//	//swap(a, b);
//	//cout << "a = " << a << endl;
//	//cout << "b = " << b << endl;
//
//	TestConstRef();
//
//	return 0;
//}

struct A
{
	int a[10000] = { 0 };
};

void Func1(A a){}

void Func2(A& a) {}

void TestRefAndValue()
{
	A a;

	//传值
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		Func1(a);
	}
	size_t end1 = clock();

	//传引用
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		Func2(a);
	}
	size_t end2 = clock();

	//两种函数运行时间
	cout << "Func1_Time:" << end1 - begin1 << endl;
	cout << "Func2_Time:" << end2 - begin2 << endl;
}

//int main()
//{
//	TestRefAndValue();
//
//	return 0;
//}


int main()
{
	int a = 10;
	int& ra = a;

	int b = 20;
	int* pb = &b;

	return 0;
}