#pragma once
#include<iostream>
using namespace std;

#include<stdlib.h>

//构造函数 与 析构函数
//typedef int DataType;
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_data = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (_data == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//
//		_capacity = 4;
//		_size = 0;
//	}
//
//	~Stack()
//	{
//		free(_data);
//		_data = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//
//private:
//	DataType* _data;
//	int _size;
//	int _capacity;
//};
//
//class Date
//{
//public:
//	//全缺省构造函数不能与无参构造函数同时存在
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//
//private:
//	//对象成员可以给缺省值--C++11，但是有显示定义的全缺省构造函数就没必要给缺省值了
//	int _year;	// 年
//	int _month;	// 月
//	int _day;	// 日
//};
//
//class MyQueue
//{
//	// 虽然没有构造函数和析构函数
//	// 但是在对象实例化时，编译器会自己调用默认构造函数和默认析构函数
//	// 用途是去调用自定义类型的默认构造和默认析构函数
//	// 系统自己生成的析构函数，内置类型成员不做处理，自定义类型会调用它的析构函数
//private:
//	Stack _pushst;
//	Stack _popst;
//};

//int main()
//{
//	// 注意：这里的不需要构造函数或者析构函数并非真的不需要，还是要根据实际需求进行设计
//	// 需要构造函数 和 析构函数
//	Stack st1;
//	Stack st2;
//
//	// 需要构造函数，但不需要析构函数
//	// 一般来说，没有动态申请的资源都不需要写析构函数
//	Date d1;
//	Date d2;
//
//	// 不需要构造函数，也不需要析构函数
//	// 需要释放资源的成员都是自定义类型也不需要写析构函数
//	MyQueue q1;
//	MyQueue q2;
//
//	//Date d1;
//	//d1.Print();
//
//	return 0;
//}

/////////////////////////////////////////////////////
//拷贝构造函数
//typedef int DataType;
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_data = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (_data == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//
//		_capacity = 4;
//		_size = 0;
//	}
//
//	// 拷贝构造函数
//	// 深拷贝--> 需要再开空间并拷贝到新的空间
//	Stack(const Stack& x)
//	{
//		_data = (DataType*)malloc(sizeof(DataType) * x._capacity);
//		if (_data == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//		memcpy(_data, x._data, sizeof(DataType) * x._capacity);
//		_capacity = x._capacity;
//		_size = x._size;
//
//	}
//
//	~Stack()
//	{
//		free(_data);
//		_data = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//
////private:
//	DataType* _data;
//	int _size;
//	int _capacity;
//};
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// 拷贝构造函数--> 构造函数的重载，参数只有一个且必须是类类型对象的引用
//	// 浅拷贝--> 值拷贝
//	// 注意：使用传值会直接报错，因为会引发无穷递归调用
//	// Date(Date x) -->错误
//	// 这里会引起无穷次自定义类型的传参拷贝
//	// C++规定内置类型直接拷贝，自定义类型必须调用拷贝构造完成拷贝
//	Date(const Date& x)
//	{
//		_year = x._year;
//		_month = x._month;
//		_day = x._day;
//	}
//	// 注意：若没有显示定义，编译器会生成默认的拷贝构造函数
//	// 内置类型成员完成值拷贝 / 浅拷贝
//	// 自定义类型成员会调用他们的拷贝构造
//
//
//	void Print()
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//
//private:
//	int _year;	// 年
//	int _month;	// 月
//	int _day;	// 日
//};
//
//class MyQueue
//{
//private:
//	Stack _pushst;
//	Stack _popst;
//};

//int main()
//{
//	//Date d1(2023, 8, 13);
//	//Date d2(d1);
//	//d2.Print();
//
//	//Stack st1;
//	//Stack st2(st1);
//
//	return 0;
//}

//////////////////////////////////////////////
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		cout << "Date()" << endl;
//	}
//
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		cout << "Stack()" << endl;
//
//		_data = (int*)malloc(sizeof(int) * capacity);
//		if (_data == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//
//		_capacity = 4;
//		_size = 0;
//	}
//
//	Stack(const Stack& x)
//	{
//		_data = (int*)malloc(sizeof(int) * x._capacity);
//		if (_data == nullptr)
//		{
//			perror("malloc fail");
//			return;
//		}
//		memcpy(_data, x._data, sizeof(int) * x._capacity);
//		_capacity = x._capacity;
//		_size = x._size;
//
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		free(_data);
//		_data = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//
//private:
//	int* _data;
//	int _size;
//	int _capacity;
//};
//
////引用的作用
////void func(Date d)  // 经过拷贝构造-->需要12字节
//void func(Date& d)	 // 语法上认为没有开空间
//{}
//
////void func(Stack st)	// 深拷贝-->代价较高
//void func(Stack& st)
//{}
//
////这里的返回值也如上的道理，最好使用引用，减少拷贝
////Stack& func()
////{
////	//前提是，出了作用域对象还在
////	static Stack st;
////	return st;
////}
//
////这里返回的是st的深拷贝
//Stack func()
//{
//	Stack st;
//	return st;
//}
//
////错误的用法
////这时会返回st的别名，已经被析构函数置空，这样的做法非常危险
////Stack& func()
////{
////	//局部对象，出了作用域就会销毁
////	Stack st;
////	return st;
////}
//
//int main()
//{
//	//Date d1(2023, 8, 13);
//	//func(d1);
//
//	//Stack st1;
//	//func(st1);
//	Stack ret = func();
//
//	return 0;
//}

/////////////////////////////////////////

//赋值运算符重载: operator
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& x)
	{
		_year = x._year;
		_month = x._month;
		_day = x._day;
	}

	void Print()
	{
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
	}

//private:
	int _year;	// 年
	int _month;	// 月
	int _day;	// 日
};

//bool Less(const Date d1, const Date d2)
//{
//	if (d1._year < d2._year)
//	{
//		return true;
//	}
//	else if (d1._year == d2._year && d1._month < d2._month)
//	{
//		return true;
//	}
//	else if (d1._year == d2._year && d1._month == d2._month && d1._day < d2._day)
//	{
//		return true;
//	}
//
//	return false;
//}

bool operator<(const Date d1, const Date d2)
{
	if (d1._year < d2._year)
	{
		return true;
	}
	else if (d1._year == d2._year && d1._month < d2._month)
	{
		return true;
	}
	else if (d1._year == d2._year && d1._month == d2._month && d1._day < d2._day)
	{
		return true;
	}

	return false;
}

int main()
{
	Date d1(2023, 8, 13);
	Date d2(2023, 7, 13);

	// 当函数名的命名并不与函数内部实现是类似或一样的功能
	// 这样会导致代码的可读性较差
	//cout << Less(d1, d2) << endl;
	//cout << Less(d2, d1) << endl;

	// 赋值运算符重载
	cout << (d1 < d2) << endl;
	cout << (d2 < d1) << endl;

	// 内部其实是这样子的
	// 正常使用不需要加operator
	//cout << operator<(d1, d2) << endl;

	return 0;
}