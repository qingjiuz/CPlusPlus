#pragma once
#include<iostream>
using namespace std;


// 动态内存申请：new和delete
class A
{
public:
	A(int a = 1, int b = 2)
		: _a(a)
		, _b(b)
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a;
	int _b;
};

// new的几种用法
// 注意需要配合delete使用
// 不要与malloc、calloc、realloc和free混合使用
//int main()
//{
//	//int* a1 = new int(20);
//	//cout << *a1 << endl;
//	//delete a1;
//
//	//int* a2 = new int(1);
//	//cout << *a2 << endl;
//	//delete a2;
//
//	int* a = new int[10] {0};
//	delete[] a;
//
//	A* aa = new A;
//	delete aa;
//
//	A* aa2 = new A(10, 20);
//	delete aa2;
//
//	A* pa = new A[10]{ 1,2,3,4 };
//	delete[] pa;
//
//	A* pa2 = new A[4]{ A(1,2), A(2,3), A(3,4), A(4,5)};
//	delete[] pa2;
//
//	return 0;
//}

//int main()
//{
//	// new和delete 与 malloc和free 虽然实际用处上没有什么区别
//	// 但是在前者在自定义类型会调用构造函数和析构函数
//
//	int* p1 = (int*)operator new(sizeof(int));
//	operator delete(p1);
//	int* pp1 = new int;
//	delete pp1;
//
//	// 顺序：
//	// new：开空间 + 构造函数
//	// new --> operator new --> malloc --> 构造函数
//	// delete：析构函数 + 释放空间
//	// delete --> 析构函数 --> operator delete --> free
//	A* p2 = (A*)operator new(sizeof(A));
//	operator delete(p2);
//	A* pp2 = new A(1, 2);
//	delete pp2;
//
//	return 0;
//}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		_array = new DataType[capacity];
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	~Stack()
//	{
//		delete _array;
//		_capacity = 0;
//		_size = 0;
//	}
//
//private:
//	DataType* _array;
//	int _size;
//	int _capacity;
//};

//int main()
//{
//	// 面向对象语言处理动态内存申请失败，一般会使用抛异常
//	// 以下是抛异常截取的实例
//	try
//	{
//		// 如果内存申请失败，会抛出异常
//		Stack* st1 = new Stack;
//		delete st1;
//	}
//	catch (const exception& e)
//	{
//		// 截取异常后在此打印
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	// 这里的pa指向的是A类的一块空间，并不是实例化出来的对象
//	A* pa = (A*)malloc(sizeof(A));
//	// 显示调用构造函数
//	new(pa)A(10, 20);
//
//	// 调用析构函数后才能对pa进行释放
//	pa->~A();
//	free(pa);
//
//	return 0;
//}



///////////////////////////////////////////////////////////////////////////////
// 模板

// 泛型编程
// 函数模板

//template<typename T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	double c = 1.1, d = 2.2;
//	char e = 'a', f = 'b';
//
//	Swap(a, b);
//	Swap(c, d);
//	Swap(e, f);
//
//	return 0;
//}

//template<class T1, class T2>
//T1 func(T1& x, T2& y)
//{
//	cout << x << " " << y << endl;
//	return x;
//}
//
//int main()
//{
//	int a = 1;
//	double b = 2.2;
//
//	int c = func(a, b);
//	cout << c << endl;
//
//	return 0;
//}

//template<class T>
//T add(const T& a, const T& b)
//{
//	return a + b;
//}
//
//template<class T>
//T* Alloc(int capacity = 4)
//{
//	return new T[capacity];
//}

//int main()
//{
//	int a1 = 1, a2 = 2;
//	double b1 = 1.1, b2 = 2.2;
//	cout << add(a1, a2) << endl;
//	cout << add(b1, b2) << endl;
//
//	// 注意模板类型的数量，以及传参的类型
//	// 这里传参时要注意，强制类型转换会生成临时变量--> 具有常性--> 需要加const
//	cout << add((double)a1, b1) << endl;
//	cout << add(a1, (int)b1) << endl;
//
//	// 显示实例化--> 使用指定类型实例化
//	cout << add<int>(a1, b1) << endl;
//	cout << add<double>(a1, b1) << endl;
//
//	// 这种类型编译器不能自己推，只能显示实例化
//	int* ptr = Alloc<int>(4);
//
//	return 0;
//}

// 类模板
// 类模板可以代替以前使用的typedef的用法--> 不用手动更改类型，更加动态

template<class T>
class Stack
{
public:
	Stack(int capacity = 4);
	//{
	//	_array = new T[capacity];
	//	_capacity = capacity;
	//	_size = 0;
	//}

	~Stack()
	{
		delete _array;
		_capacity = 0;
		_size = 0;
	}

private:
	T* _array;
	int _size;
	int _capacity;
};

// 一般不建议分开定义
// Stack<T> 这个才是Stack构造函数的类型
template<class T>
Stack<T>::Stack(int capacity)
{
	_array = new T[capacity];
	_capacity = capacity;
	_size = 0;
}

// 普通类：类名和类型是一样的
// 类模板：类名和类型有区别
int main()
{
	// Stack	  这个是类名
	// Stack<int> 这个是类型
	Stack<int> st1;
	Stack<double> st2;

	return 0;
}
