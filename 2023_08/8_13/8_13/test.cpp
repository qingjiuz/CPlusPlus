#pragma once
#include<iostream>
using namespace std;

#include<stdlib.h>

//���캯�� �� ��������
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
//	//ȫȱʡ���캯���������޲ι��캯��ͬʱ����
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
//	//�����Ա���Ը�ȱʡֵ--C++11����������ʾ�����ȫȱʡ���캯����û��Ҫ��ȱʡֵ��
//	int _year;	// ��
//	int _month;	// ��
//	int _day;	// ��
//};
//
//class MyQueue
//{
//	// ��Ȼû�й��캯������������
//	// �����ڶ���ʵ����ʱ�����������Լ�����Ĭ�Ϲ��캯����Ĭ����������
//	// ��;��ȥ�����Զ������͵�Ĭ�Ϲ����Ĭ����������
//	// ϵͳ�Լ����ɵ������������������ͳ�Ա���������Զ������ͻ����������������
//private:
//	Stack _pushst;
//	Stack _popst;
//};

//int main()
//{
//	// ע�⣺����Ĳ���Ҫ���캯��������������������Ĳ���Ҫ������Ҫ����ʵ������������
//	// ��Ҫ���캯�� �� ��������
//	Stack st1;
//	Stack st2;
//
//	// ��Ҫ���캯����������Ҫ��������
//	// һ����˵��û�ж�̬�������Դ������Ҫд��������
//	Date d1;
//	Date d2;
//
//	// ����Ҫ���캯����Ҳ����Ҫ��������
//	// ��Ҫ�ͷ���Դ�ĳ�Ա�����Զ�������Ҳ����Ҫд��������
//	MyQueue q1;
//	MyQueue q2;
//
//	//Date d1;
//	//d1.Print();
//
//	return 0;
//}

/////////////////////////////////////////////////////
//�������캯��
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
//	// �������캯��
//	// ���--> ��Ҫ�ٿ��ռ䲢�������µĿռ�
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
//	// �������캯��--> ���캯�������أ�����ֻ��һ���ұ����������Ͷ��������
//	// ǳ����--> ֵ����
//	// ע�⣺ʹ�ô�ֵ��ֱ�ӱ�����Ϊ����������ݹ����
//	// Date(Date x) -->����
//	// ���������������Զ������͵Ĵ��ο���
//	// C++�涨��������ֱ�ӿ������Զ������ͱ�����ÿ���������ɿ���
//	Date(const Date& x)
//	{
//		_year = x._year;
//		_month = x._month;
//		_day = x._day;
//	}
//	// ע�⣺��û����ʾ���壬������������Ĭ�ϵĿ������캯��
//	// �������ͳ�Ա���ֵ���� / ǳ����
//	// �Զ������ͳ�Ա��������ǵĿ�������
//
//
//	void Print()
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//
//private:
//	int _year;	// ��
//	int _month;	// ��
//	int _day;	// ��
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
////���õ�����
////void func(Date d)  // ������������-->��Ҫ12�ֽ�
//void func(Date& d)	 // �﷨����Ϊû�п��ռ�
//{}
//
////void func(Stack st)	// ���-->���۽ϸ�
//void func(Stack& st)
//{}
//
////����ķ���ֵҲ���ϵĵ������ʹ�����ã����ٿ���
////Stack& func()
////{
////	//ǰ���ǣ����������������
////	static Stack st;
////	return st;
////}
//
////���ﷵ�ص���st�����
//Stack func()
//{
//	Stack st;
//	return st;
//}
//
////������÷�
////��ʱ�᷵��st�ı������Ѿ������������ÿգ������������ǳ�Σ��
////Stack& func()
////{
////	//�ֲ����󣬳���������ͻ�����
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

//��ֵ���������: operator
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
	int _year;	// ��
	int _month;	// ��
	int _day;	// ��
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

	// �������������������뺯���ڲ�ʵ�������ƻ�һ���Ĺ���
	// �����ᵼ�´���Ŀɶ��Խϲ�
	//cout << Less(d1, d2) << endl;
	//cout << Less(d2, d1) << endl;

	// ��ֵ���������
	cout << (d1 < d2) << endl;
	cout << (d2 < d1) << endl;

	// �ڲ���ʵ�������ӵ�
	// ����ʹ�ò���Ҫ��operator
	//cout << operator<(d1, d2) << endl;

	return 0;
}