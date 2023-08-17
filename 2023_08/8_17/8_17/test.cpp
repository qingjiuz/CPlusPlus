#pragma once
#include <iostream>
using namespace std;

//nowcoder: KY258 日期累加
//class Date
//{
//public:
//    Date(int year, int month, int day)
//        : _year(year)
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
//    Date& operator+=(const int n)
//    {
//        _day += n;
//        while (_day > GetMonthDay(_year, _month))
//        {
//            _day -= GetMonthDay(_year, _month);
//            if (_month == 12)
//            {
//                ++_year;
//                _month = 0;
//            }
//            ++_month;
//        }
//        return *this;
//    }
//
//    void Print()
//    {
//        //cout << _year << "-" << _month << "-" << _day << endl;
//        printf("%d-%02d-%02d\n", _year, _month, _day);
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main() {
//    int count, year, month, day, n;
//    cin >> count;
//
//    while (cin >> year >> month >> day >> n) {
//        if (count-- == 0)
//            break;
//
//        Date d(year, month, day);
//        d += n;
//        d.Print();
//    }
//}


///////////////////////////////////////////////////////////////
//友元

//class A
//{
//	// 友元 -- 在类里面的友元只是声明 -- 定义在全局位置，且是个普通的函数
//	// 这里的func1是A类的友元
//	// 可以通过传递A类来控制类里面的所有成员
//	friend void func1(A& aa);
//public:
//	A(int a, int b)
//		: _a1(a)
//		, _a2(b)
//	{}
//
//	void func()
//	{
//		++_a1;
//		--_a2;
//	}
//
//	void Print()
//	{
//		cout << "a1:" << _a1 << "- a2: " << _a2 << endl;
//	}
//
//private:
//	int _a1;
//	int _a2;
//};
//
//class B
//{
//	// 一个函数可以是多个类的友元函数
//	friend void func1(A& aa);
//
//private:
//	int _b1 = 1;
//};
//
//void func1(A& aa)
//{
//	aa._a1;
//	aa.func();
//	aa.Print();
//}


//class A
//{
//	friend class B;	//友元类
//public:
//	void Print()
//	{
//		cout << "a = " << _a1 << endl;
//	}
//
//	void func()
//	{
//		// 错误的，无法访问友元类的成员
//		// 友元关系是单向的
//		//++_b1;
//	}
//
//private:
//	int _a1 = 1;
//};
//
//class B
//{
//public:
//	void func()
//	{
//		// 访问A类的私有成员
//		a._a1++;
//	}
//private:
//	int _b1 = 2;
//	A a;			// 友元类
//};


class A
{
public:
	void func()
	{
		++_a1;
		cout << _a1 << endl;
	}

	// 内部类
	class B
	{
	public:
		void func(const A& a)
		{
			cout << a._a1 << endl;
		}

	private:
		int _b1 = 2;
	};

private:
	int _a1 = 1;
};

int main()
{
	A::B b1;
	b1.func(A());


	return 0;
}