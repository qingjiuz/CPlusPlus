#pragma once
#include<iostream>
using namespace std;

//nowcoder:KY111 日期差值
//class Date
//{
//public:
//    Date(int date)
//        : _year(date / 10000)
//        , _month(date % 10000 / 100)
//        , _day(date % 100)
//    {}
//
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//
//    bool operator<(Date& d) const
//    {
//        if (_year < d._year)
//        {
//            return true;
//        }
//        else if (_year == d._year && _month < d._month)
//        {
//            return true;
//        }
//        else if (_year == d._year && _month == d._month && _day < d._day)
//        {
//            return true;
//        }
//        else
//        {
//            return false;
//        }
//    }
//
//    bool operator==(Date& d) const
//    {
//        if (_year == d._year && _month == d._month && _day == d._day)
//            return true;
//        else
//            return false;
//    }
//
//    bool operator!=(Date& d) const
//    {
//        return !(*this == d);
//    }
//
//    static int GetMonthDay(int year, int month)
//    {
//        static int MonthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//
//        if ((month == 2) && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
//        {
//            return MonthDay[month] + 1;
//        }
//        else
//        {
//            return MonthDay[month];
//        }
//    }
//
//    Date& operator+(int i)
//    {
//        ++_day;
//        if (_day > GetMonthDay(_year, _month))
//        {
//            _day = 1;
//            ++_month;
//            if (_month > 12)
//            {
//                ++_year;
//                _month = 1;
//            }
//        }
//        return *this;
//    }
//
//    Date& operator++()
//    {
//        *this = *this + 1;
//        return *this;
//    }
//
//    // 日期 - 日期 = 之间的天数
//    int operator-(Date& date)
//    {
//        Date max = *this;
//        Date min = date;
//        int flag = 1;
//
//        if (max < min)
//        {
//            max = date;
//            min = *this;
//            flag = -1;
//        }
//
//        int SumDay = 1;
//        while (min != max)
//        {
//            ++SumDay;
//            ++min;
//        }
//
//        return SumDay;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//int main() {
//    int date1, date2;
//    while (cin >> date1 >> date2) {
//        Date d1(date1);
//        Date d2(date2);
//
//        cout << d1 - d2 << endl;
//    }
//}

////////////////////////////////////////////////////////////////////
//nowcoder:HJ73 计算日期到天数转换

//class Date
//{
//public:
//    Date(int year, int month, int day)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {}
//
//    static int GetMonthDay(int year, int month)
//    {
//        static int MonthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//        if ((month == 2) && ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)))
//        {
//            return MonthDay[month] + 1;
//        }
//        else
//        {
//            return MonthDay[month];
//        }
//    }
//
//    int GetDateHowDay()
//    {
//        int SumDay = 0;
//        if ((_year % 4 == 0) && (_year % 100 != 0) || (_year % 400 == 0))
//        {
//            SumDay = 366 + _day;
//        }
//        else
//        {
//            SumDay = 365 + _day;
//        }
//
//        while (_month < 13)
//        {
//            SumDay -= GetMonthDay(_year, _month);
//            ++_month;
//        }
//
//        return SumDay;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    int year, month, day;
//    while (cin >> year >> month >> day) {
//        if (year >= 1000 && year < 10000
//            && month > 0 && month < 13
//            && day > 0 && day <= Date::GetMonthDay(year, month))
//        {
//            Date d1(year, month, day);
//            cout << d1.GetDateHowDay() << endl;
//        }
//    }
//}

///////////////////////////////////////////////////////////////////
//newcoder:JZ64 求1+2+3+...+n

//class Sum
//{
//public:
//    Sum()
//    {
//        _sum += _i;
//        ++_i;
//    }
//
//    static int _i;
//    static int _sum;
//};
//
//int Sum::_i = 1;
//int Sum::_sum = 0;
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        Sum a[n];
//        return Sum::_sum;
//    }
//};

///////////////////////////////////////////////////////////
//newcoder:KY222 打印日期

class Date
{
public:
    Date(int year, int day)
        : _year(year)
        , _month(1)
        , _day(day)
    {
        while (_day > GetMonthDay(_year, _month))
        {
            _day -= GetMonthDay(_year, _month);
            ++_month;
        }
    }

    static int GetMonthDay(int year, int month)
    {
        static int MonthDay[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        if ((month == 2) && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
        {
            return MonthDay[month] + 1;
        }
        else
        {
            return MonthDay[month];
        }
    }

    void Print()
    {
        printf("%d-%02d-%02d\n", _year, _month, _day);
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    int year, day;
    while (cin >> year >> day) {
        Date d(year, day);
        d.Print();
    }
}
