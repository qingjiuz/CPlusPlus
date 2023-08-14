#pragma once
#include"Date.h"

Date::Date(int year, int month, int day)
{
	if (month > 0 && month < 13 && day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "非法日期" << endl;
		assert(false);
	}
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//获取某年某月的天数
int Date::GetMonthDay(int year, int month)
{
	static int _month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
		return 29;
	else
		return _month[month];
}

//赋值运算符重载
//d1 = d2
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	return *this;
}

//d1 == d2
bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

//d1 != d2
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

//d1 < d2
bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year && _month < d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day < d._day)
	{
		return true;
	}

	return false;
}

//d1 <= d2
bool Date::operator<=(const Date& d) const
{
	return *this < d || *this == d;
}

//d1 > d2
bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}

//d1 >= d2
bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}

//日期 + 天数
Date Date::operator+(int day) const
{
	//每次调用都会调用一次拷贝构造
	//Date tmp = *this;
	//tmp._day += day;
	//while (tmp._day >= GetMonthDay(tmp._year, tmp._month))
	//{
	//	tmp._day -= GetMonthDay(tmp._year, tmp._month);
	//	if (tmp._month == 12)
	//	{
	//		tmp._year++;
	//		tmp._month = 0;
	//	}
	//	tmp._month++;
	//}
	//return tmp;

	//这里使用+=重载运算符不需要再调用拷贝构造
	Date tmp = *this;
	tmp += day;
	return tmp;
}

// 日期 += 天数
// 如果可以减少拷贝的次数，就应该选择这种版本
Date& Date::operator+=(int day)
{
	//这里的相加又会调用一次+运算符重载，会因此多拷贝构造一次数据
	//*this = *this + day;
	//return *this;

	if (day < 0)
	{
		return *this -= -day;
	}

	//这里可以直接进行日期处理
	_day += day;
	while (_day >= GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		if (_month == 12)
		{
			_year++;
			_month = 0;
		}
		_month++;
	}

	return *this;
}

// 日期 - 天数
Date Date::operator-(int day) const
{
	//Date tmp = *this;
	//
	//while (day >= tmp._day)
	//{
	//	day -= GetMonthDay(tmp._year, tmp._month);
	//	if (tmp._month == 1)
	//	{
	//		tmp._year--;
	//		tmp._month = 13;
	//	}
	//	tmp._month--;
	//}
	//tmp._day -= day;
	//return tmp;

	Date tmp = *this;
	tmp -= day;
	return tmp;
}

// 日期 -= 天数
Date& Date::operator-=(int day)
{
	//*this = *this - day;
	//return *this;

	if (day < 0)
	{
		return *this += -day;
	}

	// 1:
	//while (day >= _day)
	//{
	//	day -= GetMonthDay(_year, _month);
	//	if (_month == 1)
	//	{
	//		_year--;
	//		_month = 13;
	//	}
	//	_month--;
	//}
	//_day -= day;

	//return *this;

	// 2.
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}

// 前置++
Date& Date::operator++()
{
	//this->_day += 1;
	*this += 1;
	return *this;
}

// 后置++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

// 前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// 后置--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

//int GetYearDay(int year)
//{
//	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
//	{
//		return 366;
//	}
//	return 365;
//}

// 日期 - 日期 = 之间的天数
int Date::operator-(const Date& d) const
{
	//不够准确
	//Date tmp = d;
	//int Sum_Day = _day - tmp._day;	//三种类型的day都能处理
	//int year = _year - tmp._year;
	//int month = _month - tmp._month;
	//if (month > 0)
	//{
	//	while (tmp._month < _month)
	//	{
	//		Sum_Day += GetMonthDay(tmp._year, tmp._month);
	//		tmp._month++;
	//	}
	//}
	//else
	//{
	//	while (tmp._month > _month)
	//	{
	//		tmp._month--;
	//		Sum_Day -= GetMonthDay(tmp._year, tmp._month);
	//	}
	//}
	//if (year > 0)
	//{
	//	while (tmp._year < _year)
	//	{
	//		Sum_Day += GetYearDay(tmp._year);
	//		tmp._year++;
	//	}
	//}
	//else
	//{
	//	while (tmp._year > _year)
	//	{
	//		tmp._year--;
	//		Sum_Day -= GetYearDay(tmp._year);
	//	}
	//}
	//return Sum_Day;

	//思路较简单，更容易实现，不易出错-->不用考虑平年闰年天数的差距
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (min > max)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int day = 0;
	while (min != max)
	{
		++min;
		++day;
	}
	return day * flag;
}

// 流插入
ostream& operator<<(ostream& out, const Date& d)
{
	cout << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

// 流提取
istream& operator>>(istream& in, Date& d)
{
	int year, month, day;
	cin >> year >> month >> day;
	if (month > 0 && month < 13 && day > 0 && day <= d.GetMonthDay(year, month))
	{
		d._year = year;
		d._month = month;
		d._day = day;
	}
	else
	{
		cout << "非法日期" << endl;
		assert(false);
	}
	
	return in;

	//cin >> d._year >> d._month >> d._day;
	//return in;
}
