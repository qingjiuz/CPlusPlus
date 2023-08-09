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


//����

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

//������
void TestConstRef()
{
	const int a = 10;
	//int& ra = a;		//��ΪaΪ�������ǳ�����ֵ�ǲ��ܸı��
	const int& rra = a;

	//int& b = 10;		//��Ϊ10�ǳ����������������Ȩ�޵ķŴ�
	const int& b = 10;

	double d = 3.14;
	//int& i = d;		//���Ͳ�ͬ��������
	const int& ii = d;	//��Ϊ��ͬ���͵�ת��֮���������ʱ��������ʱ�������г���

}

//����ֵ���õĴ���ʹ��
//int& Add(int x, int y)
//{
//	//�ں���ջ֡�ڶ���ı�������Ϊ��ʱ����
//	//�ں���������ջ֡�����٣����·���������Ұָ��ı���
//	//��Ϊ�ڽ��շ���ֵ֮ǰ������ֵ���ȴ洢��ջ֡����ʱ������
//	//��������������ʱ�����ͻ���ַ���Ұָ�������
//	int sum = x + y;
//	return sum;
//}

//��ȷ�÷�
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

	//��ֵ
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		Func1(a);
	}
	size_t end1 = clock();

	//������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		Func2(a);
	}
	size_t end2 = clock();

	//���ֺ�������ʱ��
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