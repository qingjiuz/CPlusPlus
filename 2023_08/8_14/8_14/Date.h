#pragma once
#include<iostream>
using namespace std;

#include<assert.h>

class Date
{
	// 友元 --> 即使是全局的函数，使用友元声明的函数也可以使用类的对象
	// 流插入
	friend ostream& operator<<(ostream& out, const Date& d);
	// 流提取
	friend istream& operator>>(istream& in, Date& d);

public:
	// 默认构造函数
	Date(int year = 1, int month = 1, int day = 1);

	void Print() const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// 获取某年某月的天数
	int GetMonthDay(int year, int month);

	// 拷贝构造函数
	Date(const Date& d);

	// 运算符重载
	Date& operator=(const Date& d);

	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;

	// 日期 + 天数
	Date operator+(int day) const;

	// 日期 += 天数
	Date& operator+=(int day);

	// 日期 - 天数
	Date operator-(int day) const;

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
	int operator-(const Date& d) const;

private:
	int _year;
	int _month;
	int _day;
};