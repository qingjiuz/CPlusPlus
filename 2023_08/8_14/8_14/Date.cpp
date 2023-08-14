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
		cout << "�Ƿ�����" << endl;
		assert(false);
	}
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//��ȡĳ��ĳ�µ�����
int Date::GetMonthDay(int year, int month)
{
	static int _month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
		return 29;
	else
		return _month[month];
}

//��ֵ���������
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

//���� + ����
Date Date::operator+(int day) const
{
	//ÿ�ε��ö������һ�ο�������
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

	//����ʹ��+=�������������Ҫ�ٵ��ÿ�������
	Date tmp = *this;
	tmp += day;
	return tmp;
}

// ���� += ����
// ������Լ��ٿ����Ĵ�������Ӧ��ѡ�����ְ汾
Date& Date::operator+=(int day)
{
	//���������ֻ����һ��+��������أ�����˶࿽������һ������
	//*this = *this + day;
	//return *this;

	if (day < 0)
	{
		return *this -= -day;
	}

	//�������ֱ�ӽ������ڴ���
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

// ���� - ����
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

// ���� -= ����
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

// ǰ��++
Date& Date::operator++()
{
	//this->_day += 1;
	*this += 1;
	return *this;
}

// ����++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

// ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// ����--
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

// ���� - ���� = ֮�������
int Date::operator-(const Date& d) const
{
	//����׼ȷ
	//Date tmp = d;
	//int Sum_Day = _day - tmp._day;	//�������͵�day���ܴ���
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

	//˼·�ϼ򵥣�������ʵ�֣����׳���-->���ÿ���ƽ�����������Ĳ��
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

// ������
ostream& operator<<(ostream& out, const Date& d)
{
	cout << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}

// ����ȡ
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
		cout << "�Ƿ�����" << endl;
		assert(false);
	}
	
	return in;

	//cin >> d._year >> d._month >> d._day;
	//return in;
}
