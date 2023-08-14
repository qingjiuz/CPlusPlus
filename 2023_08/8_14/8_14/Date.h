#pragma once
#include<iostream>
using namespace std;

#include<assert.h>

class Date
{
	// ��Ԫ --> ��ʹ��ȫ�ֵĺ�����ʹ����Ԫ�����ĺ���Ҳ����ʹ����Ķ���
	// ������
	friend ostream& operator<<(ostream& out, const Date& d);
	// ����ȡ
	friend istream& operator>>(istream& in, Date& d);

public:
	// Ĭ�Ϲ��캯��
	Date(int year = 1, int month = 1, int day = 1);

	void Print() const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);

	// �������캯��
	Date(const Date& d);

	// ���������
	Date& operator=(const Date& d);

	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;

	// ���� + ����
	Date operator+(int day) const;

	// ���� += ����
	Date& operator+=(int day);

	// ���� - ����
	Date operator-(int day) const;

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
	int operator-(const Date& d) const;

private:
	int _year;
	int _month;
	int _day;
};