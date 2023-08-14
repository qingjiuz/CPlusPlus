#pragma once
#include<iostream>
using namespace std;

class Date
{
public:
	// 默认构造函数
	Date(int year = 1, int month = 1, int day = 1);

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// 获取某年某月的天数
	int GetMonthDay(int year, int month);

	// 拷贝构造函数
	Date(const Date& d);

	// 运算符重载
	Date& operator=(const Date& d);

	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	
	bool operator>(const Date& d);
	bool operator>=(const Date& d);

	// 日期 + 天数
	Date operator+(int day);

	// 日期 += 天数
	Date& operator+=(int day);

	// 日期 - 天数
	Date operator-(int day);

	// 日期 -= 天数
	Date& operator-=(int day);

	// 前置++
	Date& operator++();

	// 后置++
	Date operator++(int);	// operator++(0)

	// 前置--
	Date& operator--();
	
	// 后置--
	Date operator--(int);	// operator--(0)

	// 日期 - 日期 = 之间的天数
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};