#pragma once
#include<iostream>
using namespace std;

class Date
{
public:
	// Ĭ�Ϲ��캯��
	Date(int year = 1, int month = 1, int day = 1);

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);

	// �������캯��
	Date(const Date& d);

	// ���������
	Date& operator=(const Date& d);

	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	
	bool operator>(const Date& d);
	bool operator>=(const Date& d);

	// ���� + ����
	Date operator+(int day);

	// ���� += ����
	Date& operator+=(int day);

	// ���� - ����
	Date operator-(int day);

	// ���� -= ����
	Date& operator-=(int day);

	// ǰ��++
	Date& operator++();

	// ����++
	Date operator++(int);	// operator++(0)

	// ǰ��--
	Date& operator--();
	
	// ����--
	Date operator--(int);	// operator--(0)

	// ���� - ���� = ֮�������
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};