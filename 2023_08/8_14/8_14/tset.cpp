#pragma once
#include<iostream>
using namespace std;

#include"Date.h"

void TestDate()
{
	//Date d1(2023, 8, 14);
	//Date d2 = d1;			// �����ϻ��ǿ����ع�����

	//Date d3(2023, 8, 14);
	//Date d4;
	//d4 = d3;				// ���ֻ���ʹ�������������
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

// ������/����ȡ
void TestDate3()
{
	Date d1;
	Date d2;

	// һ������£������ڲ����������������ȡ�ķ�ʽ��������ʹ��ϰ��
	//d1 << cout;
	// �������ӵĴ����ǿ������������ʹ�õ�

	// ����Ҫԭ���������ڲ�����ĳ�Ա����һ��ᱻthisָ��ռ���˵�һ������
	// ����cout/cin����ֻ���ڵڶ�λ
	// ��������һ�������ֽ����ʽ
	// 1.�����ڲ��ٶ����Ա������ȡ�����ֵ --> ���ַ����Ƚ��鷳

	// 2.ʹ����Ԫ --> ����һ��ȫ�ֵĺ���
	cin >> d1 >> d2;
	cout << d1 << d2;
}

void TestDate4()
{
	Date d1(2023, 8, 14);
	d1.Print();		//d1.Print(Date* this);

	// Ȩ�޲��ܷŴ�
	// ��ˣ�Ϊ�˱�֤const���ε��Զ��������������ʹ��
	// һ��Ὣ�����޸�thisָ���ڵĶ���ĺ�������const������thisָ��
	// ����const���� --> d2.Print(const Date* this) --> Ȩ�޵�ƽ��
	const Date d2(2023, 8, 15);
	d2.Print();		//����const���Σ��ڲ����ã�d2.Print(Date* this);
	
	cout << (d2 + 100);

}


int main()
{
	TestDate4();
	
	return 0;
}
