#pragma once
#include<iostream>
using namespace std;

//class A
//{
//	//需要注意访问权限的控制
//public:
//	//需要注意声明的位置
//	void Add();
//
//	void Print()
//	{
//		cout << "Printf()" << endl;	// 虽然传入的this指针是空的，但是没有对空指针解引用
//	}
//
//	void Print(int a, int b)
//	{
//		cout << _a << endl;			// 对传入的空指针this进行了解引用-->运行错误
//	}
//
//
//private:
//	int _a;
//	int _b;
//};
//
////在类外定义函数
//void A::Add()
//{
//	cout << _a + _b << endl;
//}

//int main()
//{
//	//A a;
//	//a.Print();
//	//访问权限的问题-->使用时只能访问public的成员
//	//a.a = 10;
//	//a.b = 20;
//	//cout << a.a << endl;
//	//cout << a.b << endl;
//
//	//////////////////////////////////////////////////////////
//	//A* a;
//	//a = nullptr;
//
//	//// a调用时没有发生解引用，因此下面两个函数在编译过程中都不会出问题
//	//a->Print();			
//	//a->Print(10, 20);
//
//	return 0;
//}

//////////////////////////////////////
////创建一个简易的栈
//typedef int DataType;
//
//class Stack
//{
//public:
//	void Init(int capacity = 4)
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
//	void Push(DataType x)
//	{
//		//检查扩容
//		//...
//
//		_data[_size++] = x;
//	}
//
//	void Pop()
//	{
//		//...
//
//		_size--;
//	}
//
//	void Distroy()
//	{
//		free(_data);
//		_data = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//
//	void Print()
//	{
//		for (int i = 0; i < _size; i++)
//		{
//			cout << _data[i] << " ";
//		}
//		cout << endl;
//	}
//
//private:
//	//为避免混淆，成员变量前面最好加上"_XXXX"或者"mXXXX"，作为传参和成员变量的区分
//	DataType* _data;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Print();
//	st.Pop();
//	st.Pop();
//	st.Print();
//
//	st.Distroy();
//	return 0;
//}

////////////////////////////////////////////
//有成员变量
//class A
//{
//public:
//	void Print()
//	{
//		cout << _a << endl;
//	}
//
//private:
//	char _a;
//	int _b;
//};
//
////空类
//class B
//{};
//
////只有成员函数
//class C
//{
//	void test()
//	{}
//};
//
//int main()
//{
//	// 计算类的大小也需要注意内存对齐
//	cout << sizeof(A) << endl;	// 8 Byte
//
//	// 当类里面没有成员变量--即 空类 或者 只有成员函数 时，也会占用1Byte作为占位
//	cout << sizeof(B) << endl;	// 1 Byte
//	cout << sizeof(C) << endl;	// 1 Byte
//
//	return 0;
//}

///////////////////////////////////////////////
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// 实际上会有一个this指针传入，由编译器进行处理
//	//void print(Date* this)
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
//int main()
//{
//	Date d1;
//	d1.Init(2023, 8, 11);
//	
//	//编译器会自己传this指针
//	//d1.Print(&d1);
//	d1.Print();
//
//	return 0;
//}

///////////////////////////////////////
//创建一个简易的栈----构造函数 和 析构函数
//typedef int DataType;
//
//class Stack
//{
//public:
//	//构造函数--用类名定义的没有返回值(也不能有void)的函数
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
//	//析构函数--析构函数的函数明前面加上"~"的函数
//	~Stack()
//	{
//		free(_data);
//		_data = nullptr;
//		_size = 0;
//		_capacity = 0;
//	}
//
//	void Push(DataType x)
//	{
//		//检查扩容
//		//...
//
//		_data[_size++] = x;
//	}
//
//	void Pop()
//	{
//		//...
//
//		_size--;
//	}
//
//	void Print()
//	{
//		for (int i = 0; i < _size; i++)
//		{
//			cout << _data[i] << " ";
//		}
//		cout << endl;
//	}
//
//private:
//	DataType* _data;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	// 如果没有显示定义构造和析构函数
//	// 系统会自动生成一个无参的默认构造函数，若用户有显示定义则不会自动生成
//	// 以及系统会自动生成默认的析构函数。（不能重载）
//	Stack st1;
//	Stack st2(10);
//	// 构造函数代替了初始化，因为在对象实例化时编译器会自动调用对应的构造函数
//	//st1.Init();
//
//	st1.Push(1);
//	st1.Push(2);
//	st1.Push(3);
//	st1.Print();
//
//	// 析构函数代替了对象的清理，对象在销毁时会自动调用析构函数
//	//st1.Distroy();
//	//st2.Distroy();
//	return 0;
//}

//////////////////////////////////////////////
//构造函数（重载）
class Date
{
public:
	// 无参
	//Date()
	//{
	//	_year = 1;
	//	_month = 1;
	//	_day = 1;
	//}

	// 带参
	//Date(int year, int month, int day)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	// 带缺省参数-->>带缺省参数后，实际的功能与无参初始化的功能几乎一致
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}


	void Print()
	{
		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
	}

private:
	int _year;	// 年
	int _month;	// 月
	int _day;	// 日
};

int main()
{
	// 一般情况下，有内置类型成员就需要自己写构造函数
	// 当只有自定义类型成员时，可以考虑使用系统默认的构造函数

	Date d1(2023, 8, 12);
	Date d2;				//当无参和带缺省参数的构造函数同时存在时会报错

	d1.Print();
	d2.Print();

	//Date d3();	// 实际上会被编译器认为是函数的声明，因此通过无参创建对象时不能加括号

	// 默认的构造函数的作用
	// 没有显示定义构造函数时，系统会自动生成一个无参的默认构造函数
	// 使用默认的构造函数时，内置类型不做处理
	// 自定义类型会去调用它的构造函数
	//Date d4;
	//d4.Print();	//输出的结果是：-858993460--858993460--858993460

	return 0;
}

