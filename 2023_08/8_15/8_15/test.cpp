#pragma once
#include<iostream>
using namespace std;

//class Date
//{
//public:
//	//初始化列表
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	// 如果不加上const修饰 -->  void Print(Date* const this)
//	void Print() const		// void Print(const Date* const this)
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	// 一般都不需要自己写重载，直接使用编译器自动生成的默认取地址重载就可以
//	Date* operator&()				// 重载的是对象取地址
//	{
//		return this;
//	}
//
//	const Date* operator&() const	// 重载的是const修饰的对象取地址
//	{
//		return this;
//	}
//
//private:
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//};
//
//int main()
//{
//	Date d1(2023, 8, 15);
//	d1.Print();
//
//	const Date d2(2023, 8, 1);
//	d2.Print();
//
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//
//	return 0;
//}

////////////////////////////////////////////////////////////////
//初始化列表

//class A
//{
//public:
//	A(int val)
//		: _val(val)
//	{}
//
//private:
//	int _val;
//};
//
//class B
//{
//public:
//	// 初始化列表：对象的成员定义的位置
//	B(int a, int b)	//在初始化列表中，每个成员变量最多只能出现一次
//		: _aobj(a)
//		, _ref(b)
//		,_n(b)
//	{}
//private:
//	//以下三种情况，必须使用初始化列表初始数据
//	A _aobj;		// 没有默认构造函数 --> 即没有使用自带的无参默认构造 或 全缺省默认构造
//	int& _ref;		// 引用
//	const int _n;	// 被const修饰
//};

//class Stack
//{
//public:
//	// 默认构造函数
//	Stack(int capacity = 4)
//		: _Data((int*)malloc(sizeof(int) * capacity))
//		, _capacity(capacity)
//		,_size(0)
//	{
//		if (_Data == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		// ...
//	}
//
//	Stack(const Stack& st)
//	{
//		_Data = (int*)malloc(sizeof(int) * st._capacity);
//		if (_Data == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		memcpy(_Data, st._Data, sizeof(int) * st._capacity);
//		_capacity = st._capacity;
//		_size = st._size;
//	}
//
//	~Stack()
//	{
//		free(_Data);
//		_Data = nullptr;
//	}
//
//private:
//	int* _Data;
//	int _capacity;
//	int _size;
//};
//
//class MyQueue
//{
//public:
//	// 自己调用自定义类型的默认构造
//	MyQueue()
//	{}
//
//	// 初始化列表去调用自定义类型的默认构造
//	MyQueue(int capacity)
//		: _pushst(capacity)
//		, _popst(capacity)
//	{}
//
//private:
//	Stack _pushst;
//	Stack _popst;
//};
//
//int main()
//{
//	MyQueue q1;			// capacity = 4
//	MyQueue q2(10);		// capacity = 10
//
//	return 0;
//}


//class A
//{
//public:
//	// 初始化顺序是成员变量在类中的声明次序，与初始化列表的顺序无关
//	A(int a)
//		: _a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//private:
//	int _a2;
//	int _a1;
//};
//
//int main()
//{
//	A aa(1);
//	aa.Print();		// 1 -858993460
//
//	return 0;
//}

//////////////////////////////////////////////// 
//隐式类型转换
//class A
//{
//public:
//	// 用explicit修饰构造函数会禁止隐式类型转换
//	//explicit A(int a)
//	//	: _a(a)
//	//{}
//	
//	// 单参构造函数，没有用explicit修饰，则具有类型转换作用
//	A(int a)
//		: _a(a)
//	{}
//
//
//	A(const A& a)
//	{
//		_a = a._a;
//	}
//
//	void Print()
//	{
//		cout << _a << endl;
//	}
//	
//private:
//	int _a;
//};
//
//int main()
//{
//	// 目前认为是利用临时创建对象的机制来进行参数接收
//
//	A aa1(1);	// 构造函数
//	A aa2 = 2;	// 隐式类型转换-->整型转换成自定义类型
//	// 2先构造一个A的临时对象，然后拷贝构造给aa2 --> 这个过程会被优化成用2直接构造
//
//	// error C2440: “初始化”: 无法从“int”转换为“A &”
//	//A& aa3 = 3;
//
//	// 3构造A的临时对象，临时对象具有常属性，因此只能赋给const修饰的对象
//	const A& aa3 = 3;	
//
//	return 0;
//}

///////////////////////////////////////////////////////
// 类内用static修饰成员变量 和 成员函数
//	计算程序中创建了多少个类对象

// 1. 创建全局变量
// 劣势：全局变量在任何地方都能修改
//int _scount = 0;

//class A
//{
//public:
//	// 构造函数
//	A()
//	{
//		++_scount;
//	}
//
//	// 拷贝构造函数
//	A(const A& a)
//	{
//		++_scount;
//	}
//
//	// 析构函数
//	~A()
//	{
//		--_scount;
//	}
//
//private:
//	int _a;
//};


// 2. 在类内部创建静态的成员变量
//class A
//{
//public:
//	// 构造函数
//	A()
//	{
//		++_scount;
//	}
//
//	// 拷贝构造函数
//	A(const A& a)
//	{
//		++_scount;
//	}
//
//	// 析构函数
//	~A()
//	{
//		--_scount;
//	}
//
//	// 获取已创建类的总数
//	//int GetACount()		// int GetACount(A* const this)
//	static int GetACount()	// static int GetACount() -->	区别在于没有了this指针
//	{
//		// 静态不能调用非静态 --> 原因是没有this指针
//		//++_a1;
//
//		return _scount;
//	}
//
//	// 非静态可以调用静态 --> 内部隐藏了this指针的传递
//	void func()
//	{
//		GetACount();
//	}
//
//private:
//	// 成员变量 -- 属于每一个类对象，存储在对象里面
//	int _a1;
//	int _a2;
//
//	// 静态成员变量 -- 属于类，对类的每个对象共享，存储在静态区
//	// 由于访问限定符的限制，外部无法直接访问
//	static int _scount;	// 注意：这里的静态成员变量仅仅是声明，还需要在类外面进行初始化
//};
//
//// 静态成员初始化 --> 在全局位置才能对静态成员进行定义
//int A::_scount = 0;
//
//void func1()
//{
//	A aa1;
//	cout << __LINE__ << " : " << A::GetACount() << endl;
//}
//
//void func2()
//{
//	static A aa1;
//}
//
//
//int main()
//{
//	//A aa1;
//	//cout << __LINE__ << " : " << _scount << endl;
//	//A aa2;
//	//cout << __LINE__ << " : " << _scount << endl;
//	//func2();
//	//cout << __LINE__ << " : " << _scount << endl;
//	//func1();
//	//cout << __LINE__ << " : " << _scount << endl;
//
//	//A aa1;
//	// “A::GetACount”: 调用非静态成员函数需要一个对象 -- 没有static修饰函数
//	//cout << __LINE__ << " : " << A::GetACount() << endl;
//
//	A aa1;
//	cout << __LINE__ << " : " << A::GetACount() << endl;
//	func1();
//	cout << __LINE__ << " : " << A::GetACount() << endl;
//	func2();
//	cout << __LINE__ << " : " << A::GetACount() << endl;
//
//
//	return 0;
//}

///////////////////////////////////////////////////////
// 设计一个类，只能在 栈 或者 堆 上创建对象

class A
{
public:
	// 栈上创建一个对象
	static A GetStackObj()
	{
		A aa;
		return aa;
	}

	// 堆上创建一个对象
	static A* GetHeapObj()
	{
		return new A;
	}

private:
	int _a = 1;
};

int main()
{
	A a1;				// 栈
	static A a2;		// 静态区
	A* ptr = new A;		// 堆

	A::GetStackObj();	// 栈
	A::GetHeapObj();	// 堆

	return 0;
}
