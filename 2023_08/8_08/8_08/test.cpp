#pragma once
#include<iostream>
using namespace std;

//void func1(int a = 10, int b = 20)
//{
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//}
//
//void func2(int a, int b = 20)
//{
//	cout << "a= " << a << endl;
//	cout << "b= " << b << endl;
//}
//
//
//int main()
//{
//	func1();
//	func1(10);
//	func1(20, 10);
//	//func1(, 10);
//
//	func2(3);
//
//	return 0;
//}

//���غ���

//1.�������Ͳ�ͬ
int Add(int a, int b)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}

//2.����������ͬ

int Sum(int a, int b, int c)
{
	return a + b + c;
}

int Sum(int a, int b)
{
	return a + b;
}


//3.����˳��ͬ

void func(int a, char b)
{
	cout << "func(int a, char b)" << endl;
}

void func(char a, int b)
{
	cout << "func(char a, int b)" << endl;
}




int main()
{

	return 0;
}